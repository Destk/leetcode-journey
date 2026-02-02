#include "../include/http_client.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

std::string getJsonFromUrl(){
    HttpClient h;
    std::cout<<"Используется стандартный ресурс для обработки Json: httpbin.org/json\n";
    std::string adr = "https://httpbin.org/json";
    std::string data = h.Get(adr);
    if(data.empty()){
        std::cerr<<"Ошибка получения данных! Попробйуте позже\n";
        return "";
    }
    return data;
}

void parseAndDisplay(const std::string& str){
    if(str.empty()){
        std::cerr<<"Ошибка извлечения данных, попройбуте еще раз\n";
        return ;
    }
    json j;
    try {
        j = json::parse(str); 
    } catch (const json::parse_error& e) {
        std::cerr << "Ошибка парсинга JSON: " << e.what() << "\n";
        return;
    }
    std::string name{};
    if(j.contains("slideshow") && j["slideshow"].contains("author")){
        name = j["slideshow"]["author"];
    }
    std::string d{};
    if(j.contains("slideshow") && j["slideshow"].contains("date")){
        d = j["slideshow"]["date"];
    }
    int size{};
    std::string f{};
    if(j.contains("slideshow") && j["slideshow"].contains("slides") && j["slideshow"]["slides"].size() > 0 && j["slideshow"]["slides"][0].contains("title")){
        size = j["slideshow"]["slides"].size();
        f = j["slideshow"]["slides"][0]["title"];
    }
    std::string full_info = j.dump(4);
    std::cout<<"Ключевые данные:\n";
    std::cout<<"Автор - " << name <<'\n';
    std::cout<<"Дата - " << d <<'\n';
    std::cout<<"Размер массива - " << size << '\n';
    std::cout<<"Первый элемент - " << f << '\n';
    std::cout<<"Полный Json-file\n" << full_info <<'\n'; 
}

int main(){
    std::string json_str = getJsonFromUrl();
    parseAndDisplay(json_str);

    return 0;
}