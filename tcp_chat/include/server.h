#ifndef SERVER_H
#define SERVER_H
#include <unistd.h>
#include <netinet/in.h>  // для sockaddr_in
#include <sys/socket.h>  // для socket
#include <iostream>
class Server{
    private:
        int server_sock;
        struct sockaddr_in addr;
        int port;
    public:
        Server();
        void bindNaccept();
        ~Server();
};
#endif //SERVER_H 