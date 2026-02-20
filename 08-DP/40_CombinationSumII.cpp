#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
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
    std::vector<std::vector<int>> combinationSum2() {
        if(candidates.empty()) return {};
        std::vector<std::vector<int>> res{};
        std::vector<int> curr{};
        std::function<void(int,int)> func;
        func = [&] (int ind, int sum) {
            if(sum == target){
                res.push_back(curr);
                return;
            }
            for(size_t i = ind; i < candidates.size(); i++){
                if(i > ind && candidates[i] == candidates[i-1]) continue;
                if(sum + candidates[i] <= target){
                    curr.push_back(candidates[i]);
                    func(i+1, sum+candidates[i]);
                    curr.pop_back();
                }
            }
        };
        std::sort(candidates.begin(), candidates.end());
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
    std::cout<<"Программа для подбора комбинаций сум <2> равных таргету\n";
    char stop{};
    do{
        Solution s;
        s.inp();
        std::vector<std::vector<int>> r = s.combinationSum2();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'Y' || stop == 'y');
    return 0;
}