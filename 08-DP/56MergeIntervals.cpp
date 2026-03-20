#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Solution {
private:
    std::vector<std::vector<int>> intervals{};
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите кол-во пар: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"\nОшибка Ввода, попробуйте ещё раз\n";
                continue;
            }else{
                std::cout<<"\nВводите интервалы по правилу st < end!\n";
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите интревал через пробел: ";
                    int st, end;
                    std::cin>> st >> end;
                    if(std::cin.fail() || st > end){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout<<"\nОшибка Ввода, попробуйте ещё раз\n";
                        continue;
                    }
                    intervals.push_back({st, end});
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    std::vector<std::vector<int>> merge() {
        if(intervals.empty()) return {};
        std::vector<std::vector<int>> res{};
        std::sort(intervals.begin(), intervals.end());
        int maxel{intervals[0][1]};
        int minel{intervals[0][0]};
        for(int i = 1; i < intervals.size(); i++){
            if(maxel >= intervals[i][0]){
                maxel = std::max(maxel, intervals[i][1]);
            }else{
                res.push_back({minel, maxel});
                maxel = intervals[i][1];
                minel = intervals[i][0];
            }
        }
        res.push_back({minel, maxel});
        return res;
    }
    void out(const std::vector<std::vector<int>>& r){
        std::cout<<"Получившиеся интревалы: ";
        for(size_t i = 0; i < r.size(); i++){
            std::cout<<"[ ";
            for(size_t j = 0; j < r[i].size(); j++){
                std::cout<<r[i][j];
                if(j < r[i].size() - 1){
                    std::cout<<", ";
                }
            }
            std::cout << " ]";
        }
        std::cout<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Объединение интервалов\n";
    do{
        Solution s;
        s.inp();
        std::vector<std::vector<int>> r = s.merge();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>> stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}