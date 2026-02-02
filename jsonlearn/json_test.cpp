#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(){
    json j = {{"name", "Greg"}, {"age", 30}, {"city", "New-Castle"}};
    j["array"] = {0,6,2};
    std::string j_str = j.dump(4);
    std::cout<< "Весь JSON:\n" << j_str << '\n';
    auto n = j.value("name", "default");
    auto a = j.value("age", 0);
    auto c = j.value("city", "default");
    int el_array;
    if(j.contains("array") && j["array"].size() > 0){
        el_array = j["array"][0];
    }
    std::cout << "Извлечённые данные:\n";
    std::cout << "Имя: " << n << "\n";
    std::cout << "Город: " << c << "\n";
    std::cout << "Возраст: " << a << "\n";
    std::cout << "Первое число из array: " << el_array << "\n";
    return 0;
}