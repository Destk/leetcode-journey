#include<iostream>
#include<vector>
#include<limits>

class Solution {
private:
    int m{};
    int n{};
public:
    void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
    void inp(){
        std::cout<<"Подсчет уникальных маршрутов для работа, который идет от левого верхнего угла к правому нижнему\nРобот может двигаться только вниз и вправо\n";
        bool stop{false};
        while(!stop){
            std::cout<<"Введите кол-во строк: ";
            std::cin>>m;
            if(std::cin.fail()){
                error();
                continue;
            }
            std::cout<<"\nВведите кол-во столбцов: ";
            std::cin>>n;
            if(std::cin.fail()){
                error();
                continue;
            }
            std::cout<<'\n';
            stop = true;
        }
    }
    int uniquePaths() {
        if(m == 0 || n == 0) return 0;
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[i].size(); j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];   
            }
        }
        return dp[m-1][n-1];
    }
    void out(const int r) const{
        std::cout<<"Кол-во путей составило: "<<r<<'\n';
    }
};
void play(){
    char stop{};
    do{
        Solution robot;
        robot.inp();
        int r = robot.uniquePaths();
        robot.out(r);
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