#include "../include/http_client.h"
#include <iostream>
#include <limits>
#include <algorithm>

std::string inp() {
    std::cout << "Введите адрес: ";
    std::string s{};
    std::getline(std::cin, s);
    std::cout << '\n';
    return s;
}

std::pair<std::string, std::string> head() {
    std::cout << "Введите Заголовки по правилу (Имя - Значение):\n";
    std::pair<std::string, std::string> r;
    std::cout << "Введите имя: ";
    std::getline(std::cin, r.first);
    std::cout << "\nВведите значение: ";
    std::getline(std::cin, r.second);
    std::cout << '\n';
    return r; 
}

std::string data() {
    std::cout << "Введите данные для отправки: ";
    std::string s{};
    std::getline(std::cin, s);
    std::cout << '\n';
    return s;
}

std::string save() {
    std::cout << "Введите имя файла для сохранения: ";
    std::string s{};
    std::getline(std::cin, s);
    std::cout << '\n';
    return s;
}

void jsonparse(HttpClient& c){
    try{
        std::string add = inp();
        json j = c.GetJson(add);
        std::cout<<j.dump(4);
    }catch(std::exception& e){
        std::cerr<<"ERROR Json parse "<< e.what()<<'\n';
        return;
    }
}
int main() {
    char stop{};
    std::cout << "Программа для работы с http\n";
    
    do {
        HttpClient client;
        
        // 1. Ввод адреса
        std::string address = inp();
        
        // 2. GET без заголовков 
        // std::string get_response1 = client.Get(address);
        // std::cout << "GET без заголовков: " 
        //           << get_response1.substr(0, std::min(200, (int)get_response1.size())) 
        //           << "\n\n";
        
        // 3. Установка заголовков
        std::pair<std::string, std::string> p = head();
        client.SetHeader(p.first, p.second);
        
        // 4. GET с заголовками
        std::string get_response = client.Get(address);
        std::cout << "GET ответ (первые 200 символов): \n" 
                  << get_response.substr(0, std::min(200, (int)get_response.size())) 
                  << "\n\n";
        
        // 5. POST запрос
        std::string d = data();
        size_t pos = address.find("/get");
        if (pos != std::string::npos) {
            address.replace(pos, 4, "/post");
        }
        std::string post_response = client.Post(address, d);
        std::cout << "POST ответ (первые 200 символов): \n" 
                  << post_response.substr(0, std::min(200, (int)post_response.size())) 
                  << "\n\n";
        // 6. Сохранение POST ответа в файл
        char savef{};
        std::cout<<"Нужно ли сохранение в файл? (y/n): ";
        std::cin>>savef;
        std::cin.ignore();
        if(savef == 'y' || savef == 'Y'){
            std::string f = save();
            bool saved = client.SaveToFile(f);
            std::cout << "Сохранение файла: " << std::boolalpha << saved << "\n";
        }
        //7.Парсинг Json файлов
        char want_json{};
        std::cout << "Получить как JSON? (y/n): ";
        std::cin >> want_json;
        std::cin.ignore();
        if (want_json == 'y' || want_json == 'Y') {
            jsonparse(client);
        }
        //Для непрерывной работы 
        std::cout << "\nПродолжить? (y/n): ";
        std::cin >> stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << '\n';
        
    } while(stop == 'y' || stop == 'Y');
    
    return 0;
}