#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

class Solution {
private:
    std::vector<int> nums{};
    int target{};
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"\nВведите таргет: ";
            std::cin >> target;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }
            std::cin.ignore();
            std::cout<<"Введите элементы массива: ";
            std::string s{};
            std::getline(std::cin, s);
            std::istringstream ss(s);
            int x{};
            while(ss >> x){
                nums.push_back(x);
            }
            std::cin.ignore();
            std::cout<<'\n';
            stop = true;
        }
    }
    int threeSumClosest() {
        if(nums.empty() || nums.size() < 3) return 0;
        int sum = nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int l = i + 1;
            int r = nums.size() - 1;
            while( l < r){
                int curr_sum = nums[i] + nums[l] + nums[r];
                if(curr_sum == target){
                    return target;
                }if(std::abs(curr_sum - target) < std::abs(sum - target)){
                    sum = curr_sum;
                }if(curr_sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return sum;
    }
    void out(const int& r){
        std::cout<<"Сумма которая максимальная равная target("<<target<<"), это - "<< r <<'\n';
    }
};

int main(){
    std::cout<<"Программа на поиск сумму из 3 элементов которые приблизительно равны target\n";
    char stop{};
    do{
        Solution s;
        s.inp();
        int r = s.threeSumClosest();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}