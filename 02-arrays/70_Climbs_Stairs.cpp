#include<iostream>
#include<vector>
#include<limits>

int inp(){
    int n{};
    bool s = false;
    while(!s){
        std::cout<<"Введите кол-во шагов до вершины: ";
        std::cin>>n;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё\n";
            continue;
        }
        else{
            std::cout<<'\n';
            s = true;
        }
    }
    return n;
}

int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    std::vector<int> v{};
    v.resize(n+1);
    v[1] = 1;
    v[2] = 2;
    for(int i = 3; i <= n; i++){
        v[i] = v[i-1] + v[i-2];
    }
    return v[n];        
}

void out(int r, int n){
    std::cout<<"Кол-во шагов которые нужно проделать: \n";
    std::cout<<"n = " << n << " -> " << r << '\n';
}
int main(){
    char s;
    std::cout<<"Программа на Подъем по лестнице\n";
    do{
        int n{inp()};
        int r = climbStairs(n);
        out(r, n);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>s;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(s == 'y' || s == 'Y');
    return 0;
}