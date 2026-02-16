class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string res{};
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry{0};
        while(i >= 0|| j >= 0 || carry > 0){
            int bitA = (i >= 0) ? a[i] - '0' : 0;
            int bitB = (j >= 0) ? b[j] - '0' : 0;
            int sum = bitA + bitB + carry;
            if(sum% 2 == 0){
                res+='0';
            }else{
                res+='1';
            }
            carry = sum / 2;
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

