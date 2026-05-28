#include "../include/client.h"

Client::Client(){
    //1)Создали сокет
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(client_sock < 0){
        std::cerr <<"Ошибка создания сокета\n";
        exit(1);
    }
    //Устанавили нужный айпи
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
}
void Client::connetNsend(){
    int c = connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(c < 0){
        std::cerr<<"Не удалось присоединится к серверу!\n";
        exit(1);
    }else{
        std::cout<<"Соединение успешно установлено\n";
        std::cout<<"Введите ваше сообщение: ";
        std::getline(std::cin, message);
        send(client_sock, message.c_str(), message.size(), 0);
        std::cout<<"Собщение Отправлено: " << message << '\n';
        std::cout<<"Задейственно памяти: "<< message.size() << '\n';
    }
}
Client::~Client(){
    close(client_sock);
}