#include <iostream>
#include <vector>
class Solution {
private:
    std::vector<std::vector<int>> grid{};
    void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
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
            }else{
                grid.resize(x, std::vector<int>(y,0));
                for(int i = 0; i < x; i++){
                    for(int j = 0; j < y; j++){
                        std::cout<<"\nВведите вес пути: ";
                        int tmp{0};
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
    int minPathSum() {
        if(grid.empty()) return 0;
        int s = grid.size();
        int t = grid[0].size();
        std::vector<std::vector<int>> dp(s,std::vector<int>(t,0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < s; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < t; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < s; i++){
            for(int j = 1; j < grid[i].size();j++){
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j]; 
            }
        }
        return dp[s-1][t-1];
    }
    void out(const int r) const{
        std::cout<<"Минимальный путь составил: "<<r<<'\n';
    }
};
void play(){
    char stop{};
    std::cout<<"Задача на подсчет минимального пути. \n(из левого верхнего угла в правый нижний)\n";
    do{
        Solution s;
        s.inp();
        int r = s.minPathSum();
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