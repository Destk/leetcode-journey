class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        std::stack<char> st;
        for(char el : s){
            if(el == '(' || el == '{' || el == '['){
                st.push(el);
            }
            switch(el){
                case ')':
                    if(st.empty() || st.top() != '('){
                        return false;
                    }
                    st.pop();
                    break;
                case '}':
                    if(st.empty() || st.top() != '{'){
                        return false;
                    }
                    st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top() != '['){
                        return false;
                    }
                    st.pop();
                    break;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
