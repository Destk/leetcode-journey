class Solution {
public:
    int subtractProductAndSum(int n) {
        int p{1}, s{0};
        while(n > 0){
            int digit = n % 10;
            p*=digit;
            s+=digit;
            n/=10;
        }
        return p-s;
    }
};
