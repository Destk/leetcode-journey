#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
private:
    std::vector<int> nums{};
    int threshold{};
    bool sum(std::vector<int>& nums, int threshold, int m){
        long long sum{};
        for(size_t i = 0; i < nums.size(); i++){
            sum+=(nums[i] + m - 1)/m;
        }
        if( sum <= threshold){
            return true;
        }
        return false;
    }
public:
    void inp(){
        nums.clear();
        bool s{false};
        while(!s){
            std::cout<<"Введите кол-во элементов в массиве: ";
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
                        i--;
                        continue;
                    }
                    nums.push_back(y);
                }
                std::cout<<"\nВведите порог математических махинаций: ";
                std::cin>>threshold;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                    continue;
                }
                std::cout<<'\n';
                s =true;
            }
        }
    }
    int smallestDivisor() {
        if(nums.empty()) return 0;
        int l{1};
        int r = *std::max_element(nums.begin(), nums.end());
        while(l < r){
            int mid = l + (r - l)/2;
            if(sum(nums,threshold,mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
    void out(const int r){
        std::cout<<"Наименьший делитель: "<<r<<'\n';
    }
};

int main(){
    std::cout<<"Программа по поиску наименьшего делителя заданного числа\n";
    char s{};
    do{
        Solution d{};
        d.inp();
        int r = d.smallestDivisor();
        d.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>s;
        std::cin.ignore();
        std::cout<<'\n';
    }while(s == 'y' || s == 'Y');
    return 0;
}
