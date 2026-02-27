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
            std::cout<<"Введите кол-во элементов > 3: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }else{
                for(int i = 0; i  < x; i++){
                    int y{};
                    std::cout<<"\nВведите элемент: ";
                    std::cin>>y;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                        continue;
                    }
                    nums.push_back(y);
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    std::vector<std::vector<int>> threeSum() {
        if (nums.size() < 3) return {};
        
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    left++;
                    right--;
                    
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
    void out(const std::vector<std::vector<int>>& r){
        std::cout<<"arr = [ ";
        for(size_t i = 0; i < r.size(); i++){
            std::cout<<"[ ";
            for(size_t j = 0; j < r[i].size(); j++){
                std::cout<<r[i][j];
                if(j < r[i].size()-1){
                    std::cout<< ", ";
                }
            }
            std::cout<<" ]";
            if( i < r.size()-1) std::cout<<", ";
        }
        std::cout<<" ]\n";
    }
};

int main(){
    std::cout<<"Программа на вычисление суммы из 3 не равных элементов, которыу должны выдавать 0\n";
    char stop{};
    do{
        Solution t3;
        t3.inp();
        std::vector<std::vector<int>> r = t3.threeSum();
        t3.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}