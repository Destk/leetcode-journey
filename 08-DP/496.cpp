class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {\
        std::stack<int> st;
        st.push(0);
        std::unordered_map<int, int> map{};
        std::vector<int> res{};
        for(int i = 0; i < nums2.size(); i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                map[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        for(auto el : nums1){
            res.push_back((map.count(el) ? map[el] : -1));
        }
        return res;
    }
};
