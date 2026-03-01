#include "../include/scanner.h"
#include <sys/socket.h>    // socket, connect, setsockopt
#include <netinet/in.h>    // sockaddr_in, htons, INADDR_ANY
#include <arpa/inet.h>     // inet_pton, inet_ntop
#include <unistd.h>        // close, read, write
#include <fcntl.h>         // fcntl (для неблокирующего режима)
#include <sys/select.h>    // select, FD_SET, FD_ZERO
#include <cerrno>          // errno
#include <cstring>         // memset, strerror
#include <iostream>

bool Scanner::checkPort(const std::string& ip, int port){
    sockaddr_in sock;
    sock.sin_family = AF_INET;
    sock.sin_port = htons(port);
    sock.sin_addr.s_addr = inet_addr(ip.c_str());
    int client;
    client = socket(AF_INET, SOCK_STREAM,0);
    if(client < 0){
        std::cerr<<"Сокет не создался(возможно не правильный ip-adress), попробуйте ещё раз\n";
        return false;
    }
    int flags = fcntl(client, F_GETFL, 0);
    if(flags == -1){
        close(client);
        return false;
    }
    fcntl(client, F_SETFL, flags | O_NONBLOCK);

    int r = connect(client, (struct sockaddr*) &sock, sizeof(sock));
    if(r == 0){
        std::cout<<"Порт открыт!\n";
    }else if(errno == EINPROGRESS){
        fd_set write;
        FD_ZERO(&write);
        FD_SET(client, &write);
        struct timeval tv;
        tv.tv_sec = t;
        tv.tv_usec = 0;
        int ready = select(client + 1, NULL, &write, NULL, &tv);
        if(ready == 1){
                int error;
                socklen_t len = sizeof(error);
                if (getsockopt(client, SOL_SOCKET, SO_ERROR, &error, &len) == 0 && error == 0) {
                    std::cout << "Порт открыт!\n";
                    close(client);
                    return true;
                } else {
                    std::cerr << "Порт закрыт или фильтруется\n";
                    close(client);
                    return false;
                }
        }else if(ready == 0){
            std::cerr<<"Время ожидание превышено\n";
            close(client);
            return false;
        }else{
            std::cerr<<"Ошибка соединения\n";
            close(client);
            return false;
        }
    }else{
        std::cerr<<"Не удалось подключиться\n";
        return false;
    }
    close(client);
    return false;
}