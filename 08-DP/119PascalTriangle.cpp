#include<vector>
#include<iostream>
#include<limits>

int inp(){
    bool s = false;
    int x{};
    while(!s){
        std::cout<<"Введите индекс строки (0-33): ";
        std::cin>>x;
        if(std::cin.fail() || x < 0 || x > 33){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
        }else{
            std::cout<<"\nВывод "<<x+1<<" строки\n";
            s = true;
        }
    }
    return x;
}

std::vector<int> getRow(int rowIndex) {
    if(rowIndex == 0) return {1};
    std::vector<int> dp{1};
    for(int i = 0; i < rowIndex; i++){
        dp.push_back(1);
        for(int j = i; j >= 1; j--){
            dp[j] = dp[j-1] + dp[j];
        }
    }
    return dp;        
}

void out(std::vector<int>& r){
    for(size_t i = 0; i < r.size(); i++){
        std::cout<<r[i]<<" ";
    }
    std::cout<<'\n';
}

int main(){
    char c{};
    std::cout<<"Программа по Треугольнику Паскаля II\n";
    do{
        int numRows = inp();
        std::vector<int> r = getRow(numRows);
        out(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}  