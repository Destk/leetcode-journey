#include "../include/server.h"

Server::Server(){
    //1)Создаем сокет
    server_sock = socket(AF_INET, SOCK_STREAM,0);
    //2)Устанавливаем параметры, тип нашего соединения(TCP), свободный порт(5252), тип(любой ip из моей сети)
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5252);
    addr.sin_addr.s_addr = INADDR_ANY;
    //3)Связывываем наш сокет
    int b = bind(server_sock, (struct sockaddr*)&addr, sizeof(addr));
    if(b < 0){
        std::cerr<<"Ошибка! Соединение не установлено\n";
    }else{
    //4)Переводим наш сервер в режим ожидания
        listen(server_sock, 5);
    }
}
void Server::bindNaccept(){
    int client = accept(server_sock, NULL, NULL);
    if(client < 0){
        std::cerr<<"Ошибка установки соединения!\n";
    }else{
        std::cout << "Клиент подключился" << std::endl;
        char buf[1024];
        int bytes_read = recv(client, buf, 1024, 0);
        buf[bytes_read] = '\0';
        std::cout<<"Получено сообщение: "<< buf << '\n';
        close(client);
    }
}

Server::~Server(){
    close(server_sock);
}