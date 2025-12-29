#include<iostream>
#include<vector>
#include<limits>
#include<queue>
#include<functional>

void input(std::vector<std::vector<char>>& board){
    bool stop = false;
    while(!stop){
        std::cout<<"Введите кол-во горизонтальных линий на карте(строк) ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
            continue;
        }
        std::cout<<"Введите кол-во вертикальных линий на карте(столбцов) ";
        int x1{};
        std::cin>>x1;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
            continue;
        }
        if(x <= 0 || x1 <= 0) {
            std::cout << "Размер матрицы должен быть > 0\n";
            continue;
        }
        else{
            board.resize(x);
            for(size_t i = 0; i < x; i++) {
                board[i].resize(x1);
            }
            std::cout << "Введите матрицу в одной строке (О или X, без пробелов):\n";
            std::string line;
            for(size_t i = 0; i < x; i++){
                std::cin >> line;
                for(size_t j = 0; j < x1; j++){
                    board[i][j] = line[j];
                }
            }
            stop = true;
        }
    }
}

void solve(std::vector<std::vector<char>>& board) {
    if(board.empty()) return ;
    int str = board.size();
    int col = board[0].size();
    std::function<void(int, int)> DFS;
    DFS = [&] (int s, int c){
        if(s >= 0  && s < str && c >= 0 && c < col && board[s][c] == 'O'){
            board[s][c] = '*';
            DFS(s-1,c);
            DFS(s+1,c);
            DFS(s,c-1);
            DFS(s,c+1);
        }
    };
    //Шаг 1 замена краевые О на *
    for(int i = 0; i < str; i++){
        for(int j = 0; j < col; j++){
            if(i == 0 || i == str-1 || j == 0 || j == col-1){
                if(board[i][j] == 'O'){
                    DFS(i,j);
                }
            }
        }
    }
    //Шаг 2 замена отсавшиеся О на Х и возвращаем краявые О на место
    for(int i = 0; i < str; i++){
        for(int j = 0; j < col; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }else if(board[i][j] == '*'){
                board[i][j] = 'O';
            }
        }
    }      
}

void output(std::vector<std::vector<char>>& board){
    std::cout<<"Обновленная карта: \n";
    for(size_t i = 0; i < board.size(); i++){
        for(size_t j = 0; j < board[0].size();j++){
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<'\n';
    }
}

int main(){
    char c{};
    std::cout<<"Программа по закрашиванию центральных точек О\n";
    do{
        std::vector<std::vector<char>> board{};
        input(board);
        solve(board);
        output(board);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}