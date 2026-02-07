#include "../include/telegrambot.h"
#include <iostream>

TgBot CreateBot(const std::string& token, const std::string& state_file){
    TgBot bot(token);
    try{
        bot.Load(state_file);
    }catch(...){

    }
    return bot;
}

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

void SendMessage(TgBot& b){
    std::string txt{};
    std::cout<<"Введите текст сообщения: ";
    std::getline(std::cin,txt);
    std::cout<<'\n';
    int64_t chat_id = b.Chat_id();
    if(chat_id == -1){
        std::cout<<"Для начала напишите боту!\n";
        return ;
    }
    b.SendMessage(chat_id, txt);
    std::cout<<"Сообщение доставлено!\n";
}

void GetInfoUpdate(TgBot& b){
    std::cout<<"Последнее обновление: " << b.GetLastUpdateId() << '\n';
}

void TestForward(TgBot& bot) {
    try {
        
        int64_t from_chat_id = 671511321; 
        int64_t to_chat_id = 1043261327;       
        int64_t message_id = 123;             
        
        json forwarded = bot.ForwardMessage(to_chat_id, from_chat_id, message_id);
        std::cout << "Сообщение переслано! ID: " << forwarded["result"]["message_id"] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка пересылки: " << e.what() << std::endl;
    }
}

int main(){
    char stop{};
    do{
    try{
        std::string t = addToken();
        TgBot bot = CreateBot(t, "file_info");
        botInfo(bot);
        SendMessage(bot);
        GetInfoUpdate(bot);
        bot.Save("file_info");
        TestForward(bot);
        std::cout<<"Продолжить? (Y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }catch(std:: exception& e){
        std::cerr<<"Ошика - "<<e.what();
    }}while(stop == 'y' || stop == 'Y');
    return 0;
}