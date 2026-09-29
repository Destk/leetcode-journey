#include <iostream>
#include <vector>
#include <functional>

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
        bool stop{false};
        nums.clear();
        while(!stop){
            std::cout<<"Введите кол-во элементов в массиве: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                error();
                continue;
            }
            else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите элемент: ";
                    int y{};
                    std::cin>>y;
                    if(std::cin.fail()){
                        error();
                        i--;
                        continue;
                    }
                    nums.push_back(y);
                }
                std::cout<<'\n';
                stop = true;   
            }
        }
    }
    std::vector<std::vector<int>> permute() {
        if(nums.empty()) return {};
        std::function<void(std::vector<int>& , std::vector<bool>& )> func;
        std::vector<std::vector<int>> res{};
        std::vector<bool> use(nums.size(), false);
        std::vector<int> curr{};
        func = [&](std::vector<int>& curr, std::vector<bool>& use){
           if(curr.size() == nums.size()){
                res.push_back(curr);
                return ;
           }
           for(int i = 0; i < nums.size(); i++){
                if(use[i] == false){
                    use[i] = true;
                    curr.push_back(nums[i]);
                    func(curr, use);
                    curr.pop_back();
                    use[i] = false;
                }
           } 
        }; 
        func(curr,use);
        return res;
    }
    void out(const std::vector<std::vector<int>>& res) const{
        std::cout<<"Результат = [ ";
        for(auto vec : res){
            std::cout<<"[ ";
            for(auto el : vec){
                std::cout<<el<<" ";
            }
            std::cout<<" ] ";
        }
        std::cout<<"]\n";
    }
};
void play(){
    char stop{};
    std::cout<<"Задача на перестановки элементов в массиве\n";
    do{
        Solution p;
        p.inp();
        std::vector<std::vector<int>> r = p.permute();
        p.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
    }while(stop == 'y' || stop == 'Y');
}

int main(){
    play();
    return 0;
}