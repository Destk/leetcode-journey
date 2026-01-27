#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
size_t WriteCallback(void* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl = curl_easy_init();
    if (curl) {
        std::string response;
        curl_easy_setopt(curl, CURLOPT_URL, "https://httpbin.org/json");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == CURLE_OK) {
            std::cout << "Успех! Длина ответа: " << response.length() << " байт\n";
            std::cout << "Начало: " << response.substr(0, 100) << "\n";
        } else {
            std::cout << "Ошибка curl: " << curl_easy_strerror(res) << "\n";
        }
    }
    curl_global_cleanup();
    return 0;
}
