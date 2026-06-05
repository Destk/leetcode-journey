class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int b{0};
        int nn{n};
        while(nn > 0){
            nn = nn >> 1;
            b++;
        }
        int mask = (1 << b) - 1;
        return n ^ mask;
    }
};
