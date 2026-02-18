#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class Solution {
private:
    std::vector<int> nums{};
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите кол-во элементов в массив: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте еще раз\n";
                continue;
            }else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите элемент: ";
                    int y{};
                    std::cin>>y;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout<<"\nОшибка ввода, попробуйте еще раз\n";
                        continue;
                        i--;
                    }
                    nums.push_back(y);
                }
                std::sort(nums.begin(), nums.end());
                auto last = std::unique(nums.begin(), nums.end());
                nums.erase(last, nums.end());
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    std::vector<std::vector<int>> subsets() {
        if(nums.empty()) return {};
        std::vector<std::vector<int>> res{};
        std::vector<int> curr{};
        std::function<void(int)> backtracking;
        backtracking = [&] (int ind) {
            if(ind == nums.size()){
                res.push_back(curr);
                return;
            }

            curr.push_back(nums[ind]);
            backtracking(ind + 1);

            curr.pop_back();
            backtracking(ind + 1);
        };
        backtracking(0);
        return res;
    }
    void out(std::vector<std::vector<int>>& r){
        for(auto el : r){
            std::cout<<"[ ";
            for(auto x : el){
                std::cout<< x << " ";
            }
            std::cout<<" ]";
        }
        std::cout<<'\n';
    }
};

int main(){
    std::cout<<"Программа на Subset\n";
    char stop{};
    do{
        Solution subset;
        subset.inp();
        std::vector<std::vector<int>> r = subset.subsets();
        subset.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'Y' || stop == 'y');
}