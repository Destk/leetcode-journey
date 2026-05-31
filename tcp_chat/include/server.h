#ifndef SERVER_H
#define SERVER_H
#include <unistd.h>
#include <netinet/in.h>  // для sockaddr_in
#include <sys/socket.h>  // для socket
#include <iostream>
#include <thread> // для управления потоками
#include <chrono> // для разграничения по времени
#include <mutex> //блокировка потоков
#include <vector>
#include <algorithm>
class Server{
    private:
        int server_sock;
        struct sockaddr_in addr;
        int port;
        std::mutex mtx;
        std::vector<int> clients;
        std::mutex clientMutex;
    public:
        Server();
        void bindNaccept();
        ~Server();
        void handler(int client_sock);
};
#endif //SERVER_H 