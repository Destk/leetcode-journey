#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include <netinet/in.h>  // для sockaddr_in
#include <sys/socket.h>  // для socket
#include <arpa/inet.h>
#include <unistd.h>
class Client{
    private:
        int client_sock;
        struct sockaddr_in server_addr;
        const int port{5252};
        std::string message{};
    public:
        Client();
        void connetNsend();
        ~Client();
};
#endif //CLIENT_H