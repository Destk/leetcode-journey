#include "../include/scanner.h"
#include <iostream>

int main(int argc, char* argv[]){
    if (argc != 3) {
        std::cout << "Usage: ./portscanner <IP> <port>\n";
        return 1;
    }
    std::string ip = argv[1];
    int port = std::stoi(argv[2]);
    
    Scanner scan;
    bool open = scan.checkPort(ip, port);
    if(open){
        std::cout<<"Port " << port << "is Open!\n";
    }else{
        std::cout<<"Port " << port << "is Closed or Filtered!\n";
    }
    return 0;
}