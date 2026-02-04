#include "../include/telegrambot.h"

TgBot::TgBot(const std::string& t) : token(t) {};

json TgBot::GetMe(){
    std::string url = BASE_URL  + token +"/getMe";
    json result = bot.GetJson(url);
    if(!result["ok"]){
        throw std::runtime_error("Telegram API ERROR " + result["description"].get<std::string>());
    }
    return result["result"];
}

std::string TgBot::GetBotName(){
    json j = GetMe();
    return j["first_name"].get<std::string>();
}

int64_t TgBot::GetId(){
    json j = GetMe();
    return j["id"].get<int64_t>();
}