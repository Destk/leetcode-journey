#ifndef TG_BOT_H
#define TG_BOT_H

#include "http_client.h"

class TgBot{
    private:
        std::string token;
        HttpClient bot;
        const static inline std::string BASE_URL = "https://api.telegram.org/bot";
    public:
        TgBot(const std::string& t);
        json GetMe();
        std::string GetBotName();
        int64_t GetId();
};
#endif //TG_BOT_H