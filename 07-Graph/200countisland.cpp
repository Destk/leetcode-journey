#include <iostream>
#include <vector>
#include <queue>

class Solution {
private:
    std::vector<std::vector<char>> grid{};
public:
    void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
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
            }else{
                grid.resize(x, std::vector<char>(y,0));
                for(int i = 0; i < x; i++){
                    for(int j = 0; j < y; j++){
                        std::cout<<"\nВведите 1/0: ";
                        char tmp{};
                        std::cin>>tmp;
                        if(std::cin.fail()){
                            error();
                            i--;
                            j--;
                            continue;
                        }
                        grid[i][j] = tmp;
                    }
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    void BFS(std::queue<std::pair<int,int>>& q, std::vector<std::vector<char>>& grid){
        while(!q.empty()){
            std::pair<int,int> cord = q.front();
            q.pop();
            int x = cord.first;
            int y = cord.second;
            if(x > 0 && grid[x-1][y] == '1'){
                grid[x-1][y] = '0';
                q.push({x-1,y});
            }if( x < grid.size()-1 && grid[x+1][y] == '1'){
                grid[x+1][y] = '0';
                q.push({x+1,y});
            }if( y > 0 && grid[x][y-1] == '1'){
                grid[x][y-1] = '0';
                q.push({x,y-1});
            }if( y < grid[x].size()-1 && grid[x][y+1] == '1'){
                grid[x][y+1] = '0';
                q.push({x,y+1});
            }
        }
    }
    int numIslands() {
        if(grid.empty()) return 0;
        int count{};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    std::queue<std::pair<int,int>> q{};
                    q.push({i,j});
                    grid[i][j] = '0';
                    count++;
                    BFS(q, grid);
                }
            }
        }
        return count;
    }
    void out(const int r) const{
        std::cout<<"Максимальный кол-во островов: "<<r<<'\n';
    }
};

void play(){
    char stop{};
    std::cout<<"Задача Подсчет островов\n";
    do{
        Solution s;
        s.inp();
        int r = s.numIslands();
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