#include<iostream>
#include<vector>
#include<limits>

int inp(){
    bool s = false;
    int x{};
    while(!s){
        std::cout<<"Введите кол-во элементов: ";
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
        }else{
            std::cout<<"\nВы ввели "<<x<<" вершин\n";
            s = true;
        }
    }
    return x;
}

std::vector<std::vector<int>> generate(int numRows) {
    if(numRows== 0) return {};
    std::vector<std::vector<int>> dp{};
    dp.push_back({1});
    for(int i = 1; i < numRows; i++){
        std::vector<int> row(i+1);
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) {
                row[j] = 1;}else{
                row[j] = dp[i-1][j-1] + dp[i-1][j];
                }
        }
        dp.push_back(row);
    }
    return dp;
}

void out(std::vector<std::vector<int>>& r){
    for(size_t i = 0; i < r.size(); i++){
        for(size_t j = 0; j < r[i].size(); j++){
            std::cout<<r[i][j]<<" ";
        }
        std::cout<<'\n';
    }
}

int main(){
    char c{};
    std::cout<<"Программа по Треугольнику Паскаля\n";
    do{
        int numRows = inp();
        std::vector<std::vector<int>> r = generate(numRows);
        out(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}  