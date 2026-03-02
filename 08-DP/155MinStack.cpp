#include <iostream>
#include <vector>
#include <algorithm>

class MinStack {
    std::vector<int> data;
    std::vector<int> mins;
public:    
    void push(int val) {
        data.push_back(val);
        if(mins.empty()){
            mins.push_back(val);
        }else{
            int minval = std::min(val, mins.back());
            mins.push_back(minval);
        }
    }
    
    void pop() {
        if(!data.empty()){
            data.pop_back();
            mins.pop_back();
        }
    }
    
    int top() {
        if(data.empty()){
            return 0;
        }
        return data.back();
    }
    
    int getMin() {
        if(mins.empty()){
            return 0;
        }
        return mins.back();
    }
};

void inp(int& x){
    bool stop{false};
    while(!stop){
        std::cout<<"Введите число: ";
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
            continue;
        }else{
            stop = true;
        }
    }
}

void Menu(){
    char stop{};
    int x{};
    MinStack stack;
    do{
        std::cout<<"---Меню---\n1)Команда push\n2)Команда pop\n3)Команда top\n4)Команда min in stack\n";
        std::cout<<"Введите комнаду: ";
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
            continue;
        }
        std::cout<<'\n';
        switch(x){
            case 1: {
                int a{};
                inp(a);
                stack.push(a);
                std::cout<<"Элемент добавлен\n";
                break;
            }
            case 2: {
                stack.pop();
                std::cout<<"Элемент удален\n";
                break;
            }
            case 3:{
                std::cout << "Верхний элемент: " << stack.top() << '\n';
                break;
            }
            case 4:{
                std::cout<<"Нижний элемент: " << stack.getMin() << '\n';
                break;
            }
        }
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}

int main(){
    std::cout<<"Программа на разработку собственного стека\n";
    Menu();
    return 0;
}