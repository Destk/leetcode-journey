#include <iostream>
#include <vector>
#include <queue>
class Solution{
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
        int BFS(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>& q, int& fresh){
        int dx[] = {-1,1,0,0};
        int dy[] = { 0,0,1,-1};
        int t{0};
        while(!q.empty()){
            int sizelvl = q.size();
            for(int i = 0; i < sizelvl; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            t++;
        }
        return t - 1;
    }
    int orangesRotting() {
        if(grid.empty() || grid[0].empty()) return 0;
        int leng = grid.size();
        int weig = grid[0].size();
        std::queue<std::pair<int, int>> q{};
        int minT{};
        int fresh{};
        for(int i = 0; i < leng; i++){
            for(int j = 0; j < weig; j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        if(fresh == 0) return 0;

        minT = BFS(grid, q, fresh);

        return (fresh == 0) ? minT : -1;
    }
        void out(const int r) const{
            std::cout<<"Минимальное кол-во минут, чтобы ни в одной ячейке не осталось свежих апельсинов: " << r <<'\n';
        }
};
void play(){
    char stop{};
    do{
        Solution s;
        s.inp();
        int r = s.orangesRotting();
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