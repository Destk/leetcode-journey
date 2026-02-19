#include <iostream>
#include <vector>
#include <functional>

class Solution {
private:
    std::vector<int> candidates{};
    int target{};
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
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите элемент: ";
                    int y{};
                    std::cin>>y;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                        continue;
                        i--;
                    }
                    candidates.push_back(y);
                }
                std::cout<<"\nВведите target: ";
                std::cin>>target;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                    continue;
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    std::vector<std::vector<int>> combinationSum() {
        if(candidates.empty()) return {};
        std::vector<std::vector<int>> res{};
        std::vector<int> curr{};
        std::function<void(int, int)> func;
        func = [&] (int ind, int sum) {
            if (ind >= candidates.size()) return;
            if(sum == target){
                res.push_back(curr);
                return;
            }
            if(sum > target){
                return;
            }

           if(sum + candidates[ind]  <= target){
                curr.push_back(candidates[ind]);
                sum+=candidates[ind];
                func(ind, sum);
                sum -= candidates[ind];
                curr.pop_back();
           } 
            func(ind+1,sum);
        };
        func(0,0);
        return res;
    }
    void out(const std::vector<std::vector<int>>& r){
        std::cout<<"Получившиеся комбинации: ";
        for(size_t i = 0; i < r.size(); i++){
            std::cout<<"[ ";
            for(size_t j = 0; j < r[i].size(); j++){
                std::cout<<r[i][j];
                if(j != r[i].size() - 1){
                    std::cout<<", ";
                }
            }
            std::cout<<" ]\n";
        }
    }
};

int main(){
    std::cout<<"Программа для подбора комбинаций сум равных таргету\n";
    char stop{};
    do{
        Solution s;
        s.inp();
        std::vector<std::vector<int>> r = s.combinationSum();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'Y' || stop == 'y');
    return 0;
}