#include<iostream>
#include<vector>
#include<limits>

void input(std::vector<std::vector<int>>& trust, int& n){
    bool stop = false;
    while(!stop){
        std::cout<<"Введите кол-во людей в городе: ";
        std::cin >> n;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            std::cout<<"\nСоздадим матрицу, введите кол-во строк и столбцов: ";
            int x,y{};
            std::cin>>x>>y;
            if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
            continue;
            }
            trust.assign(x, std::vector<int>(y));
            std::cout<<"Вводите связи между людьми в городе\n";
            std::cout<<"Правило: К судье всегда есть доверие, но у судьи нет доверия ни к кому\n";
            for(auto& str : trust){
                for(auto& el : str){
                    std::cin>>el;
                }
            }
            stop = true;
        }
    }
}

int findJudge(int n, std::vector<std::vector<int>>& trust) {
    std::vector<int> trusted(n+1, 0);
    std::vector<int> trusting(n+1, 0);
    for(const auto& t : trust){
        trusting[t[0]]++;
        trusted[t[1]]++;
    }
    for(int i = 1; i <= n; i++){
        if(trusting[i] == 0&& trusted[i] == n-1){
            return i;
        }
    }
    return -1;
}

void output(int r){
    if(r >= 0){
    std::cout<<"В городе был найден судья и это - " << r <<'\n';
    }else{
        std::cout<<"Судья отсутсвует в городе\n";
    }
}
int main(){
    std::cout<<"Программа по поиску судьи в городе\n";
    char c{};
    do{
        std::vector<std::vector<int>> trust{};
        int n{};
        input(trust,n);
        int r = findJudge(n,trust);
        output(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}