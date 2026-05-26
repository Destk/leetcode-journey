class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        if(prices.empty()) return {};
        std::stack<int> st;
        st.push(0);
        std::vector<int> res(prices.size(), 0);
        for(int i = 0; i < prices.size(); i++){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                res[st.top()] = prices[st.top()] - prices[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            res[st.top()] = prices[st.top()];
            st.pop();
        }
        return res;
    }
};
