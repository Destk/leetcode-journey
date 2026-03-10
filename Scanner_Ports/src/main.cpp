#include "../include/scanner.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::vector<int> scan_ports(const std::string& ip, int start, int end){
    Scanner scan;
    std::vector<int> open_port{};
    for(int i = start; i < end; i++){
        if(scan.checkPort(ip, i)){
            open_port.push_back(i);
        }
    }
    return open_port;
}

void out(const std::vector<int>& open_port){
    std::cout<<"Открытые порты: ";
    for(auto el : open_port){
        std::cout<< el << ' ';
    }
    std::cout<<'\n';
}

int main(int argc, char* argv[]){
    if (argc != 4) {
        std::cout << "Использование: ./scanner <ip> <start_port> <end_port>\n";
        return 1;
    }
    std::string ip = argv[1];
    std::string start_port = argv[2];
    std::string end_port = argv[3];
    int start = std::stoi(start_port);
    int end = std::stoi(end_port);
    if (start > end) {
        std::swap(start, end);
    }
    std::vector<int> ports = scan_ports(ip, start, end);
    out(ports);
    return 0;
}