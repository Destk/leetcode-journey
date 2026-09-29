#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class Solution {
private:
    std::vector<int> candidates{}; 
    int target{};
    void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
public:
    void inp(){
        candidates.clear();
        bool st{false};
        while(!st){
            std::cout<<"Введите таргет: ";
            std::cin>>target;
            if(std::cin.fail()){
                error();
                continue;
            }
            std::cout<<"\nВведите кол-во элементов в массиве: ";
            int n{};
            std::cin>>n;
            if(std::cin.fail()){
                error();
                continue;
            }
            for(int i = 0; i < n; i++){
                std::cout<<"\nВведите элемент: ";
                int el{};
                std::cin>>el;
                if(std::cin.fail()){
                    error();
                    i--;
                    continue;
                }
                candidates.push_back(el);
            }
            std::cout<<'\n';
            st = true;
        }
    }
    std::vector<std::vector<int>> combinationSum2() {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res{};
        std::function<void(int step, int sum)> func;
        std::vector<int> curr{};
        func = [&](int step, int sum){
            if(sum > target) return; 
            if(sum == target){
                res.push_back(curr);
                return;
            }
            for(int i = step; i < candidates.size(); i++){
                if(i > step && candidates[i] == candidates[i-1]) continue;
                curr.push_back(candidates[i]);
                func(i+1, sum + candidates[i]);
                curr.pop_back();
            }
        };
        func(0,0);
        return res;
    }
    void out(const std::vector<std::vector<int>>& r)const{
        std::cout<<"Получившийся массив чисел, сумма которых равна "<< target<<" : ["; 
        for(auto vec : r){
            std::cout<<" [ ";
            for(auto el : vec){
                std::cout<< el << " ";
            }
            std::cout<<" ]";
        }
        std::cout<<" ]\n";
    }
};

void play(){
    char stop{};
    std::cout<<"Программа на нахождение всех уникальных сумм равных таргету.\n";
    do{
        Solution c;
        c.inp();
        std::vector<std::vector<int>> r = c.combinationSum2();
        c.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
    }while(stop == 'y' || stop == 'Y');

}

int main(){
    play();
    return 0;
}