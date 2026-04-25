#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

class Solution {
private:
    std::vector<std::vector<char>> maze{};
    std::vector<int> entrance{};
public:
    void inp(){
            bool stop{false};
            while(!stop){
                std::cout<<"Введите кол-во строк: ";
                int x{};
                std::cin>>x;
                if(std::cin.fail()){
                    error();
                    continue;
                }
                std::cout<<"\nВведите кол-во столбцов: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    error();
                    continue;
                }
                maze.resize(x);
                for(int i = 0; i < x; i++){
                    maze[i].resize(y);
                }
                for(size_t i = 0; i < maze.size(); i++){
                    for(size_t j = 0; j < maze[i].size(); j++){
                        std::cout<<"\nВведите grid["<<i<<"]["<<j<<"] : ";
                        std::cin>>maze[i][j];
                        if(std::cin.fail()){
                            error();
                            i--;
                            j--;
                            continue;
                        }
                    }
                }
                std::cout << "\nВведите стартовst кординаты: ";
                entrance.clear();
                for(int i = 0; i < 2; i++){
                    int val;
                    std::cin >> val;
                    if(std::cin.fail()){
                        error();
                        i--;
                        continue;
                    }
                    entrance.push_back(val);
                }
                stop = true;
                std::cout<<'\n';
            }
        }
        void error(){
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
        }
    int BFS(std::vector<std::vector<char>>& maze, std::vector<int>& entrance){
        int row = maze.size();
        int colm = maze[0].size();
        if (entrance[0] < 0 || entrance[0] >= row || entrance[1] < 0 || entrance[1] >= colm) {
        return -1;
        }
        if (maze[entrance[0]][entrance[1]] != '.') {
            return -1;
        }
        std::queue<std::tuple<int,int,int>> q{};
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+'; // отмечаем первую клетку
        //массивы для проверки сторон
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()){
            auto [x, y, step] = q.front();
            q.pop();
            if((x == 0 || y == 0 || x == row - 1 || y == colm - 1) && !(x == entrance[0] && y == entrance[1])){
                return step;
            }
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx  < row && ny >= 0 && ny < colm && maze[nx][ny] == '.'){
                    maze[nx][ny] = '+';
                    q.push({nx,ny,step+1});
                }
            }
        }
        return -1;
    }
    int nearestExit() {
        if(maze.empty() || maze[0].empty()) return -1;
        return BFS(maze, entrance);
    }
    void out(const int r) const{
            std::cout<<"Ближайший выход от старта находится в " << r <<" шагах\n";
        }
};

void play(){
    char stop{};
    std::cout<<"Программа на Ближайший выход из лабиринта\n";
    do{
        Solution s;
        s.inp();
        int r = s.nearestExit();
        s.out(r);
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