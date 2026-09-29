#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

class Solution {
private:
    std::vector<int> nums{};
public:
    void inp(){
        bool stop = false;
        while(!stop){
            std::cout<<"Введите кол-во значений в векторе: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите значение: ";
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
                stop = true;
                std::cout<<'\n';
            }
        }
    }
    int majorityElement() {
        if(nums.empty()) return 0;
        std::unordered_map<int,int> map;
        int maxcount{};
        int result{};
        for(size_t i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            if(map[nums[i]] > maxcount){
                maxcount = map[nums[i]];
                result = nums[i];
            }
        }
        return result;
    }
    void out(int r){
        std::cout<<"Самый встречающийся элемент - "<<r<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Программа по поиску самого встречаемого элемента из массива\n";
    do{
        Solution Maj;
        Maj.inp();
        int r = Maj.majorityElement();
        Maj.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while( stop == 'y' || stop == 'Y');
    return 0;
}