#include <iostream>
#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> obstacleGrid{};
public:
    void inter(){
        std::cout<<"Программа на подсчет путей для робота.\n";
        std::cout<<"----Правила----\n";
        std::cout<<"1.Робот может двигаться только вниз или вправо\n";
        std::cout<<"2.Робот идет из левого верхенго угла, вправый нижний угол\n";
        std::cout<<"3. <1> - обозначение препятсвие\n3.1. <0> - пустая клетка\n";
    }
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите размер строк: ";
            int m{};
            std::cin>>m;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }
            std::cout<<"\nВведите кол-во столбцов: ";
            int n{};
            std::cin>>n;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }
            else{
                obstacleGrid.resize(m,std::vector<int>(n));
                for(size_t i = 0; i < obstacleGrid.size(); i++){
                    for(size_t j = 0; j < obstacleGrid[0].size(); j++){
                        std::cout<<"\nВведите объект: ";
                        int x{};
                        std::cin>>x;
                        if(std::cin.fail()){
                            std::cin.clear();
                            std::cin.ignore();
                            std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                            i--;
                            j--;
                            continue;
                        }
                        obstacleGrid[i][j] = x;
                    }
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    int uniquePathsWithObstacles() {
        if(obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;
        std::vector<std::vector<int>> path(obstacleGrid.size(), std::vector<int>(obstacleGrid[0].size(), 0));
        for(size_t i = 0; i < obstacleGrid.size(); i++){
            for(size_t j = 0; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 1){
                    path[i][j] = 0;
                }else if(i == 0 && j == 0){
                    path[i][j] = 1;
                }else if(i == 0){
                    path[0][j] = path[0][j-1];
                }else if(j == 0){
                    path[i][0] = path[i-1][0];
                }else{
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
        }
        return path[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
    void out(int r){
        std::cout<<"Максимальное кол-во путей от левого угла до правого угла для робоато составило - "<<r<<'\n';
    }
};

int main(){
    char stop{};
    do{
        Solution p;
        p.inter();
        p.inp();
        int r = p.uniquePathsWithObstacles();
        p.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}