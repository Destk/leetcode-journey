#include<iostream>
#include<vector>
#include<limits>
#include<queue>



class Solution {
private:
    std::vector<std::vector<int>> grid{};
public:
     void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
    void inp(){
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
                grid.resize(x);
                for(size_t i = 0; i < x; i++) {
                    grid[i].resize(x1);
                }
                std::cout << "Введите матрицу (0 или 1):\n";
                for(size_t i = 0; i < x; i++){
                    for(size_t j = 0; j < x1; j++){
                        std::cout<<"Введите кординаты клетки по x & y\n";
                        std::cout << "[" << i << "][" << j << "]: ";
                        std::cin>>grid[i][j];
                        std::cout<<'\n';
                    }
                }
                stop = true;
            }
        }
    }
    int BFS(std::vector<std::vector<int>>& grid, int i, int j){
        std::queue<std::pair<int,int>> q{};
        q.push({i, j});
        grid[i][j] = 0;
        int count{1};
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1){
                    count++;
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland() {
        if(grid.empty() || grid[0].empty()) return 0;
        int str = grid.size();
        int tab = grid[0].size();
        int maxS{0};
        for(int i = 0; i < str; i++){
            for(int j = 0; j < tab; j++){
                if(grid[i][j] == 1){
                    int S = BFS(grid, i, j);
                    maxS = std::max(maxS, S);
                }
            }
        }
        return maxS;
    }
    void out(int r){
    if(r != 0){
        std::cout<<"Площадь самого крупного острова на карте составляет "<<r<<'\n';
    }else{
        std::cout<<"Один океан, на ближайших просторах нет островов\n"; 
    }
}
};

void play(){
    char stop{};
    std::cout<<"Задача Подсчет островов\n";
    do{
        Solution s;
        s.inp();
        int r = s.maxAreaOfIsland();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}

int main(){
    play();
    return 0;
}   