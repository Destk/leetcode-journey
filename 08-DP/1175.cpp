class Solution {
public:
    long long factorial(int x){
        const int MOD = 1000000007;
        long long fact = 1;
        for (int i = 1; i <= x; i++) {
            fact = (fact * i) % MOD;
        }
        return fact;
    }
    int numPrimeArrangements(int n) {
        std::vector<bool> vec(n+1, true);
        vec[0] = vec[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(vec[i]){
                for(int j = i*i; j <= n; j+=i){
                    vec[j]=false;
                }
            }
        }
        int c{0};
        for(auto el : vec){
            if(el){
                c++;
            }
        }
        int nn = n-c;
        long long result = (factorial(c) * factorial(nn)) % 1000000007;
        return (int)result;
    }
};
