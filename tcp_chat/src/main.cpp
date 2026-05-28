#include "../include/server.h"
#include "../include/client.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./tcp_chat server|client" << std::endl;
        return 1;
    }

    std::string mode = argv[1];

    if (mode == "server") {
        Server serv;
        serv.bindNaccept();
    } 
    else if (mode == "client") {
        Client client;
        client.connetNsend();
    } 
    else {
        std::cerr << "Unknown mode. Use 'server' or 'client'" << std::endl;
        return 1;
    }

    return 0;
}