#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
class Solution {
private:
    std::vector<int> height{};
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введит кол-во элементов в векторе: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cin.clear();
                std::cout<<"\nОшибка ввода, попробуйет ёще раз!\n";
                continue;
            }else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите элемент: ";
                    int y{};
                    std::cin>>y;
                    if(std::cin.fail()){
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cin.clear();
                        std::cout<<"\nОшибка ввода, попробуйет ёще раз!\n";
                        i--;
                    }
                    height.push_back(y);
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    int maxArea() {
        if(height.empty()) return 0;
        int r = height.size() - 1;
        int l{0};
        int maxS{0};
        while( l < r ){
            int t = (r - l) * std::min(height[l],height[r]);
            maxS = std::max(maxS,t);
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxS;
    }
    void out(int r){
        std::cout<<"Ответ: "<<r<<'\n';
    }
};

int main(){
    char c{};
    do{
        Solution s;
        s.inp();
        int r = s.maxArea();
        s.out(r);
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}