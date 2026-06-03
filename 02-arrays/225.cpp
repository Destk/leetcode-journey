class MyStack {
private:
    std::queue<int> q1; //Основное хранилище
    std::queue<int> q2; //Вспомогательное, для поддасовки элементов
public:
    MyStack() : q1(), q2() {};
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1,q2);
    }
    
    int pop() {
        int del = q1.front();
        q1.pop();
        return del;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

