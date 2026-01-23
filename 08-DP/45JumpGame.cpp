#include <iostream>
#include <vector>
#include <limits>
class Solution {
private:
    std::vector<int> nums{};
public:
    void SetN(){
        bool s{false};
        while(!s){
            std::cout<<"Введите кол-во элементов в массиве: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите число: ";
                    int y{};
                    std::cin>>y;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                        i--;
                        continue;
                    }
                    nums.push_back(y);
                }
                std::cout<<'\n';
                s = true;
            }
        }
    }
    int jump() {
        if(nums.size() == 1 || nums.empty()) return 0;
        int j{1};
        int end{nums[0]};
        int maxJ{0};
        for(int i = 0; i < nums.size()-1; i++){
            maxJ = std::max(maxJ, i + nums[i]);
            if( i == end ){
                j++;
                end = maxJ;
            }
        }
        return j;
    }
    void Outr(int r){
        if(r == 0) {
            std::cout<<"Прыжки равны 0, вы уже в конце массива\n";
        } else {
            std::cout<<"Минимальное кол-во прыжков: "<<r<<'\n';
        }
    }
};


int main(){
    char c{};
    std::cout<<"Программа по Прыжкам 2\n";
    do{
        Solution jum;
        jum.SetN();
        int r = jum.jump();
        jum.Outr(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}