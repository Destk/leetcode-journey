#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> nums{};
public:
    void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
    void inp(){
            bool c = false;
            while(!c){
                std::cout<<"Введите кол-во элементов: ";
                int x{};
                std::cin>>x;
                if(std::cin.fail()){
                    error();
                    continue;
                }else{
                    nums.resize(x);
                    for(int i = 0; i < x; i++){
                        std::cout<<"\nВведите элемент "<<i<<": ";
                        std::cin>>nums[i];
                        if(std::cin.fail()){
                            error();
                            i--;
                            continue;
                        }
                    }
                    c = true;
                }
            }
    }
    int maxProduct() {
        if(nums.empty()) return 0;
        int maxel{nums[0]};
        int minel{nums[0]};
        int res{nums[0]};
        for(int i = 1; i < nums.size(); i++){
            int tmpmax = std::max({nums[i],maxel*nums[i],minel*nums[i]});
            int tmpmin = std::min({nums[i],maxel*nums[i],minel*nums[i]});
            maxel = tmpmax;
            minel = tmpmin;
            res = std::max(maxel,res);
        }
        return res;
    }
    void out(const int r) const{
        std::cout<<"Максимальное произведение: " << r <<'\n';
    }
};

void play(){
    char stop{};
    do{
        Solution s;
        s.inp();
        int r = s.maxProduct();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}

int main(){
    std::cout<<"Программа на поиск максимального произведения и подстроки!\n";
    play();
    return 0;
}