#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
class Solution {
private:
std::vector<std::vector<int>> intervals{};
std::vector<int> newInterval{};
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
                    std::cout<<"Введите интервал для вставки: ";
                    int x,y;
                    std::cin>>x>>y;
                    if(std::cin.fail() || x > y){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout<<"\nОшибка Ввода, попробуйте ещё раз\n";
                        continue;
                    }
                    newInterval.push_back(x);
                    newInterval.push_back(y);
                    stop = true;
                }
            }
        }
    std::vector<std::vector<int>> insert() {
        //1.Base case
        if(intervals.empty()) return {newInterval};
        if(newInterval.empty()) return intervals;
        //2.Additional structures
        std::vector<std::vector<int>> s{};
        int newSt{newInterval[0]};
        int newEnd{newInterval[1]};
        bool flag{false};
        //3.Cycle
        for(size_t i = 0; i < intervals.size(); i++){
            if(intervals[i][1] < newSt){
                s.push_back({intervals[i][0], intervals[i][1]});
            }
            else if(intervals[i][0] > newEnd){
                if(!flag){
                    s.push_back({newSt, newEnd});
                    flag = true;
                }
                s.push_back(intervals[i]);
            }else{
                newSt = std::min(intervals[i][0], newSt);
                newEnd = std::max(intervals[i][1], newEnd);
            }
        }
        if(!flag){
            s.push_back({newSt, newEnd});
        }
        //4.return
        return s;
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
    std::cout<<"Вставка интервалов в правильном порядке\n";
    do{
        Solution s;
        s.inp();
        std::vector<std::vector<int>> r = s.insert();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>> stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}