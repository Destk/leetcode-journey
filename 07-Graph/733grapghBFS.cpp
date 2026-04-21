#include <iostream>
#include <vector>
#include <queue>
class Solution {
private:
    std::vector<std::vector<int>> image{};
    int sr{}; 
    int sc{}; 
    int color{};
public:
    void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите стартовые координаты (x&y)\n: ";
            std::cin>>sr>>sc;
            if(std::cin.fail()){
                error();
                continue;
            }
            std::cout<<"\nВведите neu farbe: ";
            std::cin>>color;
            if(std::cin.fail()){
                error();
                continue;
            }
            std::cout<<"\nВведите кол-во строк: ";
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
                image.resize(x, std::vector<int>(y,0));
                for(int i = 0; i < x; i++){
                    for(int j = 0; j < y; j++){
                        std::cout<<"\nВведите farbe: ";
                        int tmp{};
                        std::cin>>tmp;
                        if(std::cin.fail()){
                            error();
                            i--;
                            j--;
                            continue;
                        }
                        image[i][j] = tmp;
                    }
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    std::vector<std::vector<int>> floodFill() {
        int oldcolor = image[sr][sc];
        if(oldcolor == color) return image;
        std::queue<std::pair<int,int>> q{};
        q.push({sr,sc});
        image[sr][sc] = color;
        std::vector<int> dx = {-1,1,0,0};
        std::vector<int> dy = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && image[nx][ny] == oldcolor){
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
    void out(std::vector<std::vector<int>>& r){
        for(auto vec : r){
            for(auto el : vec){
                std::cout<< el << " ";
            }
            std::cout<<'\n';
        }
    }
};

void play(){
    char stop{};
    std::cout<<"Задача закрашивание пикселей\n";
    do{
        Solution s;
        s.inp();
        std::vector<std::vector<int>> r = s.floodFill();
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