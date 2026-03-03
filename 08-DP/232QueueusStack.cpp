#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> queue;
    std::stack<int> temp;
public:
    void push(int x) {
        queue.push(x);
    }
    
    int pop() {
        if(temp.empty()){
            while(!queue.empty()){
                temp.push(queue.top());
                queue.pop();
            }
        }
        int res = temp.top();
        temp.pop();
        return res;
    }
    
    int peek() {
        if(temp.empty()){
            while(!queue.empty()){
                temp.push(queue.top());
                queue.pop();
            }
        }
        return temp.top();
    }
    
    bool empty() {
        if(queue.empty() && temp.empty()){
            return true;
        }
        return false;
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
    MyQueue q;
    do{
        std::cout<<"---Меню---\n1)Команда push\n2)Команда pop\n3)Команда peek\n4)Команда empty\n";
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
                q.push(a);
                std::cout<<"Элемент добавлен\n";
                break;
            }
            case 2: {
                q.pop();
                std::cout<<"Элемент удален\n";
                break;
            }
            case 3:{
                std::cout << "Верхний элемент: " << q.peek() << '\n';
                break;
            }
            case 4:{
                    if(q.empty()){
                        std::cout<<"Очередь пуста\n";
                    }else{
                        std::cout<<"Очередь не пуста\n";
                    }
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
    std::cout<<"Реализация очереди с помощью стека\n";
    Menu();
    return 0;
}