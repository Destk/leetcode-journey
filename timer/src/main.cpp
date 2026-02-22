#include <iostream>
#include "../include/timer.h"

void inter(){
    std::cout<<"---Интерфейс---\n";
    std::cout<<"1. Запуск таймера\n";
    std::cout<<"2. Остановить таймер\n";
    std::cout<<"3. Считать еще один круг\n";
    std::cout<<"4. Сброс таймера\n";
    std::cout<<"5. Проверка на запущени ли таймер\n";
    std::cout<<"Введите команду: ";
}

void inp(timer& s){
    bool stop{false};
    while(!stop){
        inter();
        int x{};
        std::cin>>x;
        std::cout<<'\n';
        if(std::cin.fail() || x <= 0 || x > 5){
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            switch (x)
            {
            case 1:
                std::cout<<"Таймер запущен\n";
                s.start();
                break;
            case 2:
                std::cout << "Прошло: " << s.stop() << " сек\n";
                stop = true;
                break;
            case 3:
                std::cout << "Круг: " << s.lap() << " сек\n";
                break;
            case 4:
                s.reset();
                std::cout << "Таймер сброшен\n";
                break;
            case 5:
                std::cout << (s.isRunning() ? "Таймер запущен" : "Таймер не запущен") << '\n';
                break;
            }
        }
    }
}

int main(){
    std::cout<<"Программа: Таймер\n";
    char stop{};
    do{
        timer t;
        inp(t);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}