#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
private:
    std::vector<int> nums{};
    std::vector<std::vector<int>> res{};
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
                        i--;
                        continue;
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
    void Setres(const std::vector<int>& curr){
        res.push_back(curr);
    }
    std::vector<std::vector<int>> Getres(){
        return res;
    }
    void backtrack(std::vector<int>& curr, int ind, const std::vector<int>& nums){
        if(ind == nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        backtrack(curr, ind+1, nums);
        curr.pop_back();

        backtrack(curr, ind+1, nums);
    }
    std::vector<std::vector<int>> subsets() {
        std::vector<int> curr{};
       backtrack(curr,0,nums);
       return Getres(); 
    }
void out(const std::vector<std::vector<int>>& r) {
        for(const auto& row : r) {
            std::cout << "[ ";
            for(int val : row) {
                std::cout << val << " ";
            }
            std::cout << "] ";
        }
        std::cout << '\n';
    }
};

int main() {
    Solution sol;
    sol.inp();
    std::vector<std::vector<int>> result = sol.subsets();
    sol.out(result);
    return 0;
}