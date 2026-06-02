class MinStack {
private:
    std::vector<int> data;
    std::vector<int> minData;
public:
    MinStack() : data(), minData() {};
    
    void push(int val) {
        data.push_back(val);
        if(minData.empty()){
            minData.push_back(val);
        }
        else{
            int m = std::min(val, minData.back());
            minData.push_back(m);
        }
    }
    
    void pop() {
        int x = data.back();
        data.pop_back();
        minData.pop_back();
        
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minData.back();
    }
};

