#include<iostream>
#include<limits>
#include<vector>
#include<algorithm>

void input(std::vector<int>& numbers, int& target){
    bool c{false};
    while(!c){
        std::cout<<"Введите target: ";
        std::cin>>target;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }
        std::cout<<"\nВведите кол-во элементов в массиве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            for(int i = 0; i < x; i++){
                std::cout<<"\nВводите элемент массива: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                    i--;
                    continue;
                }
                numbers.push_back(y);
            }
            std::sort(numbers.begin(), numbers.end());
            c = true;
        }
    }
}

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> ind{};
    int l = 0;
    int r = numbers.size()-1;
    while(l < r){
        int sum = numbers[l]+numbers[r];
        if(sum==target){
            ind.push_back(l+1);
            ind.push_back(r+1);
            break;
        }
        else if(sum > target){
            r--;
        }else{
            l++;
        }
    }    
    return ind;
}

void output(std::vector<int>& r, int target){
    std::cout<<"Элементы которые равны " << target <<": [ ";
    for(auto el : r){
        std::cout<<el<<" ";
    }
    std::cout<<" ]\n";
}
int main(){
    char c{};
    do{
        std::vector<int> numbers{};
        int target{};
        input(numbers,target);
        std::vector<int> r = twoSum(numbers, target);
        output(r, target);
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}