#include <iostream>
#include <limits>
#include "../include/manager.h"

int menu(){
    bool s{false};
    int x{};
    while(!s){
        std::cout<<"Главное меню: \n Выберете задачу из ниже перечисленных\n" <<
        "1. add - добавить новую задачу\n" <<
        "2. done <id> - пометить выполнение\n"<<
        "3. list - показать все задачи\n"<<
        "4. edit <id> - открыть меню редактирования\n"
        "5. save - Создать и сохранить в файл\n"<<
        "Введите номер - ";
        std::cin>>x;
        if(std::cin.fail()|| x > 5 || x < 1){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            std::cout<<'\n';
            s=true;
        }
    }
    return x;
}

int menu2(){
    bool s{false};
    int x{};
    while(!s){
        std::cout<<"Подменю edit <id>: \n"<<
        "1. Добавить комментарий\n"<<
        "2. Пометить как выполненную\n"<<
        "3. Вернуться в главное меню\n";
        std::cin>>x;
        if(std::cin.fail()|| x > 3 || x < 1){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            std::cout<<'\n';
            s=true;
        }
    }
    return x;
}
int main(){
    char stop{};
    Manager m;
    std::cout<<"Вас приветсвует Task Manager!\n Пристуми к работе \n";
    do{
        int w = menu();
        if(w == 1){
            std::string deadline,text,name;
            std::cout<<"Введите название: ";
            std::cin.ignore();
            std::getline(std::cin,name);
            std::cin.ignore();
            std::cout<<"Введите описание: ";
            std::getline(std::cin,text);
            std::cin.ignore();
            std::cout<<"Введите время выполнения: ";
            std::getline(std::cin,deadline);
            std::cin.ignore();
            m.addTask(name,text,deadline);
            std::cout<<'\n';
        }else if(w == 2){
            int id{};
            std::cout<<"Введите id: ";
            std::cin>>id;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }
            m.markTaskDone(id);
        }else if(w == 3){
            m.listAll();
        }else if(w == 4){
            int id{};
            std::cout<<"Введите id: ";
            std::cin>>id;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }
            int n = menu2();
            if(n == 1){
                std::string comment{};
                std::cout<<"\nВведите комментарий: ";
                std::cin.ignore();
                std::getline(std::cin,comment);
                m.addCommentToTask(id,comment);
                std::cout<<'\n';
            }else if(n == 2){
                m.markTaskDone(id);
            }            
        }else if(w == 5){
            std::string filename{};
            std::cout<<"Введите имя файла\n";
            std::cin.ignore();
            std::getline(std::cin,filename);
            m.saveToFile(filename);
        }
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(stop =='Y' || stop =='y');
    return 0;
}