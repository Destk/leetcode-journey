#include<iostream>
#include<vector>
#include<limits>
#include<queue>
#include<fstream>
#include<string>

void loggin(const std::string& txt){
    std::ofstream out("Log.txt", std::ios::app);
    if(!out){
        std::cerr<<"ERROR\n";
    }
    out << txt << '\n';
    out.close();
}

void input(std::vector<std::vector<int>>& isConnected){
    bool stop = false;
    while(!stop){
        std::cout<<"Введите кол-во городов ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }
        else{
            isConnected.resize(x);
            for(size_t i = 0; i < x; i++) {
                isConnected[i].resize(x);
            }
            std::cout << "Введите матрицу (0 или 1):\n";
            for(size_t i = 0; i < x; i++){
                for(size_t j = 0; j < x; j++){
                    std::cout<<"Введите кординаты города по x & y\n";
                    std::cout << "[" << i << "][" << j << "]: ";
                    std::cin>>isConnected[i][j];
                    std::cout<<'\n';
                }
            }
            stop = true;
        }
    }
}

int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    int province{};
    std::vector<bool> visited(isConnected.size(), false);
    std::queue<int> q{};
    for(int i = 0; i < isConnected.size();i++){
        if(!visited[i]){
            province++;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(int j = 0; j < isConnected.size();j++){
                    if(isConnected[curr][j] == 1){
                        if(visited[j] == false){
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
    }
    return province;
}

void output(int r){
    if(r != 0){
        std::cout<<"Общее количество провинций "<<r<<'\n';
    }else{
        std::cout<<"Провинций нет\n";
    }
}

int main(){
    char c{};
    std::cout<<"Программа по нахождению провинций\n";
    do{
        std::vector<std::vector<int>> isConnected{};
        input(isConnected);
        int r = findCircleNum(isConnected);
        output(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}