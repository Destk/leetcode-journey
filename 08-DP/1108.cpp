class Solution {
public:
    string defangIPaddr(string address) {
        std::string s;
        for(auto st : address){
            if(st == '.'){
                s += "[.]";
            }else{
                s+=st;
            }
        }
        return s;
    }
};
