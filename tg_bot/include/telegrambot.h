#ifndef TG_BOT_H
#define TG_BOT_H

#include "http_client.h"
#include <fstream>

class TgBot{
    private:
        std::string token;
        HttpClient bot;
        const static inline std::string BASE_URL = "https://api.telegram.org/bot";
        int64_t last_update_id;
    public:
        TgBot(const std::string& t);
        json GetMe();
        std::string GetBotName();
        int64_t GetId();
        json SendMessage(int64_t chat_id, const std::string& txt);
        int64_t Chat_id();
        json GetUpdates(int64_t offset, int64_t limit, int64_t timeout);
        int64_t GetLastUpdateId() const;
        void Save(std::string fn);
        void Load(std::string fn);
};
#endif //TG_BOT_H