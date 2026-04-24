#include <iostream>
#include <vector>
#include <queue>

class Solution {
private:
    std::vector<std::vector<int>> grid{};
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
                grid.resize(x);
                for(int i = 0; i < x; i++){
                    grid[i].resize(y);
                }
                for(int i = 0; i < grid.size(); i++){
                    for(int j = 0; j < grid[i].size(); j++){
                        std::cout<<"\nВведите grid["<<i<<"]["<<j<<"] : ";
                        std::cin>>grid[i][j];
                        if(std::cin.fail()){
                            error();
                            i--;
                            j--;
                            continue;
                        }
                    }
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
    void BFS(std::vector<std::vector<int>>& grid, int i, int j, int rows, int cols){
        std::queue<std::pair<int,int>> q{};
        q.push({i,j});
        grid[i][j] = 0;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1){
                    grid[nx][ny] = 0;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numEnclaves() {
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int j = 0; j < cols; j++){
            if(grid[0][j] == 1) BFS(grid, 0, j, rows, cols);
            if(grid[rows-1][j] == 1) BFS(grid, rows-1, j, rows, cols);
        }
        for(int i = 0; i < rows; i++){
            if(grid[i][0] == 1) BFS(grid, i, 0, rows, cols);
            if(grid[i][cols-1] == 1) BFS(grid, i, cols-1, rows, cols);
        }
        int count{0};
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
    void out(const int r) const{
            std::cout<<"Минимальная S острова, окруженного водой: " << r <<'\n';
        }
};
void play(){
    char stop{};
    std::cout<<"Программа на на подсчет S анклава в окене\n";
    do{
        Solution s;
        s.inp();
        int r = s.numEnclaves();
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