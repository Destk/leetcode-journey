#include "../include/monitor.h"
#include <limits>

int main(){
    std::setlocale(LC_TIME, "ru_RU.UTF-8");
    char stop{};
    std::cout<<"Программа для монитора файлов в проекте\n";
    Monitor m;
    do{
        std::string p;
        m.setPath();
        m.SetI();
        m.run();
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(stop == 'y' || stop == 'Y');
    return 0;
}