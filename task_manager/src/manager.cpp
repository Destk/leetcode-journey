#include "../include/manager.h"
#include "../include/task.h"
#include <iostream>
Manager::Manager() : nextid(1), tasks({}) {};

void Manager::addTask(const std::string&  name, const std::string& text, const std::string& date){
    Task m(nextid, name, text, date);
    tasks.push_back(m);
    nextid++;
}

void Manager::removeTask(int id){
    for(size_t i = 0; i < tasks.size(); i++){
        if(tasks[i].getID() == id){
            tasks.erase(tasks.begin()+i);
            break;
        }
    }
}

void Manager::markTaskDone(int id){
    for(size_t i = 0; i < tasks.size(); i++){
        if(tasks[i].getID() == id){
            tasks[i].markDone();
            break;
        }
    }
}

void Manager::listAll() const{
    for(size_t i = 0; i < tasks.size(); i++){
        std::cout<<tasks[i].getInfo()<<'\n';
    }
}

void Manager::saveToFile(const std::string& filename){
    std::ofstream file(filename);
    if(!file.is_open()){
        std::cerr<<"Ошибка открытия файла\n";
        return;
    }
    for(size_t i = 0; i < tasks.size(); i++){
        file << tasks[i].getInfo() << '\n';
    }
    file.close();
}

void Manager::addCommentToTask(int id, const std::string& comment){
    for(size_t i = 0; i < tasks.size(); i++){
        if(tasks[i].getID() == id){
            tasks[i].addComment(comment);
            break;
        }
    }
}
Manager::~Manager(){

}