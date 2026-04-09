#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> nums{};
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите кол-во элементов в массиве: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ёще раз\n";
                continue;
            }else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите элемент: ";
                    int y{};
                    std::cin>>y;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout<<"\nОшибка ввода, попробуйте ёще раз\n";
                        continue;
                    }
                    nums.push_back(y);
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    int lengthOfLIS() {
        if(nums.empty()) return 0;
        std::vector<int> dp(nums.size(), 1);
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
    void out(int r){
        std::cout<<"Длина самой длинной строго возрастающей подпоследовательности: " << r << '\n';
    }
};

void play(){
    char stop{};
    std::cout<<"Задача на поиск наибольшей возрастающей подпоследовательности\n";
    do{
        Solution s;
        s.inp();
        int r = s.lengthOfLIS();
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