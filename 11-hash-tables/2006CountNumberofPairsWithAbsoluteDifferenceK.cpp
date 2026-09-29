#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>
#include<fstream>
#include<string>
#include <cstdlib>

void logger(const std::string& msg){
    std::ofstream out("log.txt", std::ios::app);
    if(!out.is_open()){
        std::cerr<<"ERROR\n";
    }
    out << msg << '\n';
    out.close();
}
void input(std::vector<int>& nums, int& k){
    bool stop = false;
    while(!stop){
        std::cout<<"Введите абсолютную разницу К: ";
        std::cin>>k;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            logger("Input error for K");
            continue;
        }else{
            logger("User entered K: " + std::to_string(k));
            std::cout<<"\nВведите кол-во элементов в массиве: ";
            int x{};
            std::cin>>x;
            for(int i = 0; i < x; i++){
                std::cout<<"\nВведите элемент в массив: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                    i--;
                    continue;
                }
                nums.push_back(y);
            }
            stop = true;
        }
    }
}

int countKDifference(std::vector<int>& nums, int k) {
    std::unordered_map<int,int> m{};
    int maxpair{};
    for(auto& x : nums){
       if(m.count(x-k)){
            maxpair+=m[x-k];
       }if(m.count(x+k)){
            maxpair+=m[x+k];
       }
       m[x]++; 
    }
    return maxpair;
}

void output(int r, int k){
    if(r>0){
        std::cout<<"Кол-во пар с абсолютной разницой равной  "<<k<<" - "<<r<<'\n';
    }else{
        std::cout<<"Нет пар, у которых абсолютная разница равна " << k <<'\n';
    }
}
int main(){
    char stop{};
    std::cout<<"Программа по поиску количества пар с абсолютной разностью K.\n";
    logger("Started new calculation session");
    do{
        std::vector<int> nums{};
        int k{};
        input(nums, k);
        int r = countKDifference(nums, k);
        logger("Calculation finished. Result: " + std::to_string(r));
        output(r,k);
        logger("The end problems 2006");
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(stop == 'y' || stop == 'Y');
    std::cout << "\n--- LOG FILE CONTENT ---\n";
    system("cat log.txt");
    return 0;
}