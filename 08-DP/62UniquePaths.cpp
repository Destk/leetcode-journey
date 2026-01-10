#include<iostream>
#include<vector>
#include<limits>

void inp(int& m, int& n){
    bool c = false;
    while(!c){
        std::cout<<"Введите вертикальную m координату: ";
        std::cin>>m;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте еще раз\n";
            continue;
        }
        std::cout<<"\nВведите горизонтальную n координату: ";
        std::cin>>n;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте еще раз\n";
            continue;
        }
        else{
            std::cout<<"\nX = "<<m<<" -- "<<"Y = "<<n<<'\n';
            c = true;
        }
    }
}

int uniquePaths(int m, int n) {
    if(m == 0 || n == 0) return 0;
    if(m == 1 && n == 1) return 1;
    std::vector<std::vector<int>> dp(m, std::vector<int>(n,0));
    dp[0][0] = 1;
    for(int i =0; i < m;i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            if(i == 0){
                dp[i][j] = dp[i][j-1];
            }else if(j == 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
        }
    }
    return dp[m-1][n-1];
}

void out(int r){
    if(r != 0){
        std::cout<<"Кол-во путей в правый нижний угол составило: "<< r <<'\n';
    }else{
        std::cout<<"Кол-во путей 0\n";
    }
}
int main(){
    char s{};
    do{
        int m{}, n{};
        inp(m,n);
        int r = uniquePaths(m,n);
        out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>s;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(s == 'y' || s == 'Y');
    return 0;
}