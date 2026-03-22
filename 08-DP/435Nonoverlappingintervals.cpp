#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
class Solution {
private:
    std::vector<std::vector<int>> intervals{};
public:
    void inp(){
        bool stop{};
        while(!stop){
            std::cout<<"Введите кол-во пар: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите интервал: ";
                    int st, end;
                    std::cin>>st >> end;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"\nОшибка ввода, попробуйте ещё раз!";
                        i--;
                        continue;
                    }
                    intervals.push_back({st, end});
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    int eraseOverlapIntervals() {
        if(intervals.empty()) return 0;
        auto comp = [](const std::vector<int> st, const std::vector<int> end){
                return st[1] < end[1];
        };
        std::sort(intervals.begin(), intervals.end(), comp);
        int count{};
        int last_end{intervals[0][1]};
        for(size_t i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < last_end){
                count++;
            }else{
                last_end = intervals[i][1];
            }
        }
        return count;
    }
    void out(const int r){
        std::cout<<"Кол-во возможных удалений: "<< r<< '\n';
    }
};

int main(){
    std::cout<<"Программа на Непересекающиеся интервалы\n";
    char stop{};
    do{
        Solution s;
        s.inp();
        int r = s.eraseOverlapIntervals();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}