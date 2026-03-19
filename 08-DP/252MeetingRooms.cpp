#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Solution{
    private:
        std::vector<std::pair<int,int>> v;
    public:
        void inp(){
            bool s{false};
            while(!s){
                std::cout<<"Введите кол-во интервалов: ";
                int x{};
                std::cin>>x;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ошибка ввода, попробуйте ещё раз!\n";
                    continue;
                }else{
                    std::pair<int,int> tmp;
                    std::cout<<"\nИнтервалы принимаются по правилу st < end\n";
                    for(int i = 1; i < x; i++){
                        std::cout<<"\nВведите интервал (st->end): ";
                        int st, end;
                        std::cin>>st>>end;
                        if(std::cin.fail()){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                            continue;
                        }
                        if(st < end){
                            tmp.first = st;
                            tmp.second = end;
                            v.push_back(tmp);
                        }else{
                            std::cout<<"\nОшибка ввода, попробуйте еще раз!\n";
                            continue;
                        }
                    }
                    s = true;
                }
            }
        }

        bool intcheck(){
            if(v.empty()) return true;
            std::sort(v.begin(), v.end());
            for(size_t i = 0; i < v.size(); i++){
                int prev_el = v[i-1].second;
                int curr_el = v[i].first;
                if(prev_el >= curr_el){
                    return false;
                }
            }
            return true;
        }

        void check(bool r){
            if(r){
                std::cout<<"Пересечений нет! "<< std::boolalpha <<r << '\n';
            }else{
                std::cout<<"Пересечения есть! "<<std::boolalpha <<r << '\n';
            }
        }
};

int main(){
    char stop{};
    do{
        Solution s;
        s.inp();
        bool r = s.intcheck();
        s.check(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(stop == 'y' || stop == 'Y');
}