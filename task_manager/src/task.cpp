#include "../include/task.h"

Task::Task(int id,const std::string& name, const std::string& text, const std::string& deadline) : name_(name), text_(text), comment_(""), deadline_(deadline), status_(false), id_(id) {};

void Task::markDone(){
    status_ = true;
}

void Task::addComment(const std::string& text){
    comment_ = text;
}

std::string Task::getDeadline() const{
    return deadline_;
}

int Task::getID() const{
    return id_;
}

std::string Task::getName() const{
    return name_;
}

std::string Task::getInfo() const{
    std::string res = "ID - " + std::to_string(id_) + '\n' + "Name - " + name_ + '\n' + "Description - " + text_ + '\n' + "Deadline - " + deadline_ + '\n' + "Status - " + std::to_string(status_) + '\n' + "Comment - " + comment_ + '\n';
    return res;
}

bool Task::isStatus() const{
    return status_;
}