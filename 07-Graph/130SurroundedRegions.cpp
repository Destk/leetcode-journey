#include<iostream>
#include<vector>
#include<limits>
#include<queue>
#include<functional>


class Solution {
private:
    std::vector<std::vector<char>> board{};
public:
    void error(){
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
    void input(){
        bool stop = false;
        while(!stop){
            std::cout<<"Введите кол-во горизонтальных линий на карте(строк) ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                error();
                continue;
            }
            std::cout<<"Введите кол-во вертикальных линий на карте(столбцов) ";
            int x1{};
            std::cin>>x1;
            if(std::cin.fail()){
                error();
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
    void bfs(std::vector<std::vector<char>>& board, int i, int j, int row, int colm){
        std::queue<std::pair<int,int>> q{};
        q.push({i,j});
        board[i][j] = '$';
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < row && ny >= 0 && ny < colm && board[nx][ny] == 'O'){
                    board[nx][ny] = '$';
                    q.push({nx,ny});
                }
            }
        }
    }
    void solve() {
        if(board.empty() || board[0].empty()) return ;
        int row = board.size();
        int colm = board[0].size();
        for(int j = 0; j < colm; j++){
            if(board[0][j] == 'O') bfs(board, 0, j, row, colm);
            if(board[row-1][j] == 'O') bfs(board, row-1, j, row, colm);
        }
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O') bfs(board, i, 0, row, colm);
            if(board[i][colm-1] == 'O') bfs(board, i, colm-1, row, colm);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < colm; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void output(){
        std::cout<<"Обновленная карта: \n";
        for(size_t i = 0; i < board.size(); i++){
            for(size_t j = 0; j < board[0].size();j++){
                std::cout<<board[i][j]<<" ";
            }
            std::cout<<'\n';
        }
    }
};
void play(){
    char stop{};
    std::cout<<"Программа по закрашиванию центральных точек О\n";
    do{
        Solution s;
        s.input();
        s.solve();
        s.output();
        std::cout<<"Продолжить ?(y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}
int main(){
    play();
    return 0;
}

/*РЕШЕНИЕ ЧЕРЕЗ DFS 
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
*/