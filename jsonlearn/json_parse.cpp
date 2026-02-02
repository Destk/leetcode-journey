#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(){
    std::string json_str = R"({"slideshow" :{
        "author" : "Greg",
        "slides" : [{"title" : "First slide"}, {"title" : "Second slide"}],
        "end" : "The end"
        } 
    })";
    json j = json::parse(json_str);
    std::string a{};
    if(j.contains("slideshow") && j["slideshow"].contains("author")){
        a = j["slideshow"]["author"];
    }
    int size{};
    if(j.contains("slideshow") && j["slideshow"].contains("slides")){
        size = j["slideshow"]["slides"].size();
    }
    std::string f{};
    if(j.contains("slideshow") && j["slideshow"].contains("slides") && j["slideshow"]["slides"].size() > 0 && j["slideshow"]["slides"][0].contains("title")){
        f = j["slideshow"]["slides"][0]["title"];
    }
    std::string e{};
    if(j.contains("slideshow") && j["slideshow"].contains("end")){
        e = j["slideshow"]["end"];
    }
    std::cout<<"Весь Json: \n";
    std::cout<<"Автор - " << a <<'\n';
    std::cout<<"Кол-во слайдов - " << size <<'\n';
    std::cout<<"Значение первого слайда - " << f <<'\n';
    std::cout<< e;
    return 0;
}