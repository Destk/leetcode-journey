#include "../include/telegrambot.h"

TgBot::TgBot(const std::string& t) : token(t), last_update_id(0) {};

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

json TgBot::SendMessage(int64_t chat_id, const std::string& txt){
    std::string url = BASE_URL + token + "/sendMessage";

    json j;
    j["chat_id"] = chat_id;
    j["text"] = txt;
    bot.SetHeaders("Content-Type", "application/json");
    std::string data = j.dump();
    std::string response = bot.Post(url, data);
    json result = json::parse(response);
    if(!result["ok"]){
        throw std::runtime_error("Telegram API ERROR " + result["description"].get<std::string>());
    }
    return result;
}

int64_t TgBot::Chat_id(){
    GetUpdates(last_update_id, 100, 0);
    std::string url = BASE_URL + token + "/getUpdates";
    json j = bot.GetJson(url);
    if(!j["ok"]){
        throw std::runtime_error("Telegram API ERROR " + j["description"].get<std::string>());
    }
    if(j["result"].size() > 0 && j["result"][0].contains("message")){
        return j["result"][0]["message"]["chat"]["id"];
    }
    return -1;
}

json TgBot::GetUpdates(int64_t offset, int64_t limit, int64_t timeout){
    std::string url = BASE_URL + token + "/getUpdates?offset=" + std::to_string(offset) + "&timeout=" + std::to_string(timeout);
    json j = bot.GetJson(url);
    if(!j["ok"]){
        throw std::runtime_error("Telegram API ERROR " + j["description"].get<std::string>());
    }
    if(j["result"].size() > 0){
        int64_t max_id{0};
        for(int i = 0; i < j["result"].size(); i++){
            if(j["result"][i]["update_id"].get<int64_t>() > max_id){
                max_id = j["result"][i]["update_id"].get<int64_t>();
            }
        }
        last_update_id  = max_id;
    }
    return j["result"];
}

int64_t TgBot::GetLastUpdateId() const{
    return last_update_id;
}

void TgBot::Save(std::string fn){
    std::ofstream out;
    out.open(fn);
    if(out.is_open()){
        out << last_update_id; 
    }else{
        throw std::runtime_error("Error File's open");
    }
    out.close();
}

void TgBot::Load(std::string fn){
    std::ifstream out;
    out.open(fn);
    if(out.is_open()){
        int64_t s{0};
        out >> s;
        if(out.fail()){
            throw std::runtime_error("File doesn't contain a number");
        }
        last_update_id = s;
    }
    out.close();
}