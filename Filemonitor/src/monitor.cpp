#include "../include/monitor.h"
#include <thread>

using namespace std :: chrono_literals;
Monitor::Monitor(const std::string& p) : path(p) {};
Monitor::Monitor(){}
std::string Monitor::GetT() const{
    auto n = std::chrono::system_clock::now();  
    std::time_t t = std::chrono::system_clock::to_time_t(n);
    std::stringstream ss;
    ss << "[" << std::put_time(std::localtime(&t), "%H:%M") << "]";
    return ss.str();  
}

void Monitor::SetI(){
    std::cout<<"Установите интервал показаний в секундах: ";
    std::cin>>interval;
    std::cout<<'\n';
}

void Monitor::setPath(){
    std::cout<<"Введите путь к проекту: ";
    std::getline(std::cin, path);
    std::cout<<'\n';
};

void Monitor::run(){
    Fileinfo curr;
    curr.update(path);
    std::cout<<this->GetT()<<" Scan: \n" ;
    curr.Get();
    prevresult = curr;
    int ticket{0};
    if(stop){
        std::this_thread::sleep_for(std::chrono::seconds(interval));
        Fileinfo new_curr;
        new_curr.update(path);
        int delta = new_curr.getLines() - prevresult.getLines();
        int delcpp = new_curr.getCppCount() - prevresult.getCppCount();
        int delh = new_curr.getHCount() - prevresult.getHCount();
        std::cout<<this->GetT()<<" Diff: Lines +" <<delta <<", file*cpp +" << delcpp<<", file*h +" << delh <<'\n';
        new_curr.Get();
        ticket++;
        if(ticket == 5){
            stop = false;
        }
    }
}