class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        if(temperatures.empty()) return {};
        std::stack<int> st;
        st.push(0);
        std::vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
