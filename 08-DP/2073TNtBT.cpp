#include <iostream>
#include <queue>
#include <vector>
#include <limits>

class Solution {
private:
    std::vector<int> tickets{};
    int k{};
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
                    tickets.push_back(y);
                }
                std::cout<<"\nВведите нужный ind для проверки: ";
                std::cin>>k;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                    continue;
                }
                stop = true;
                std::cout<<'\n';
            }
        }
    }
    int timeRequiredToBuy() {
        if(tickets.empty() || k < 0) return 0;
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < tickets.size(); i++) {
            q.push({i, tickets[i]});
        }
        int sec{};
        while(!q.empty()){
            int ind = q.front().first;
            int need = q.front().second;
            q.pop();
            sec++;
            need--;
            if(need != 0){
                q.push({ind, need});
            }
            if(ind == k && need == 0) return sec;
        }
        return 0;
    }
    void out(int r){
        std::cout<<"Затраченное время на покупку билетов по очреди, составляет - "<<r<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Программа по подсчёту времени на покупку билетов\n";
    do{
        Solution Maj;
        Maj.inp();
        int r = Maj.timeRequiredToBuy();
        Maj.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while( stop == 'y' || stop == 'Y');
    return 0;
}