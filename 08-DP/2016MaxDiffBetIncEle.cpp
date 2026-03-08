#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> nums{};
public:
    void inp(){
        bool s{false};
        while(!s){
            std::cout<<"Введите кол-во элементов в массив: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }
            for(int i = 0; i < x; i++){
                std::cout<<"\nВведите элемент: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                    continue;
                }
                nums.push_back(y);
            }
            std::cout<<'\n';
            s = true;
        }
    }
    int maximumDifference() {
        if(nums.empty()) return -1;
        int res{};
        for(size_t i = 0; i < nums.size(); i++){
            for(size_t j = i + 1; j < nums.size(); j++){
                if(nums[i] < nums[j]){
                    res = std::max(res, nums[j] - nums[i]);
                }
            }
        }
        return res == 0 ? -1 : res;
    }
    void out(int r){
        std::cout<<"Ответ: "<<r<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Максимальная разница между возрастающими элементами\n";
    do{
        Solution s;
        s.inp();
        int r = s.maximumDifference();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout << '\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}      