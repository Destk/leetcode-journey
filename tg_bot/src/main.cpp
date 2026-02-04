#include "../include/telegrambot.h"
#include <iostream>

std::string addToken(){
    std::cout<<"Введите токен бота: ";
    std::string token;
    std::getline(std::cin, token);
    return token;
}

void botInfo(TgBot& b){
    std::string name = b.GetBotName();
    int64_t id = b.GetId();
    std::cout<<"--- Bot Info ---\n";
    std::cout<<"Имея Бота - " << name <<'\n' << "Id бота - " << id <<'\n';
    std::cout<<"-----------------\n";
}
int main(){
    char stop{};
    do{
    try{
        std::string t = addToken();
        TgBot bot(t);
        botInfo(bot);
        std::cout<<"Продолжить? (Y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }catch(std:: exception& e){
        std::cerr<<"Ошика - "<<e.what();
    }}while(stop == 'y' || stop == 'Y');
    return 0;
}