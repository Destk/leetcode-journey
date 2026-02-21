#include <iostream>
#include <vector>
#include <functional>

class Solution {
private:
    int k; 
    int n;
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите кол-во элементов в 1 комбинации: ";
            std::cin>>k;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте еще раз!\n";
                continue;
            }
            std::cout<<"\nВведите target: ";
            std::cin>>n;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте еще раз!\n";
                continue;
            } 
            else{
                std::cout<<'\n';
                stop = true;
            }           
        }
    }
    std::vector<std::vector<int>> combinationSum3() {
        if( n == 0 || k == 0) return {};
        std::vector<std::vector<int>> res{};
        std::vector<int> curr{};
        std::function<void(int,int)> func;
        func = [&] (int ind, int sum) {
            if(curr.size() == k){
                if(sum == n){
                    res.push_back(curr);
                    return;
                }
            }
            if(sum > n) return;
            for(int i = ind; i <= 9; i++){
                curr.push_back(i);
                sum += i;
                func(i+1, sum);
                curr.pop_back();
                sum -= i;
            }
        };
        func(1,0);
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
    std::cout<<"Программа для проверки комбинаций сум\n";
    char stop{};
    do{
        Solution s;
        s.inp();
        std::vector<std::vector<int>> r = s.combinationSum3();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}