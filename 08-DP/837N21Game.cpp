class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;
        
        vector<double> dp(k + maxPts, 0.0);
        
        for (int i = k; i < k + maxPts; i++) {
            dp[i] = (i <= n) ? 1.0 : 0.0;
        }
        
        double windowSum = 0.0;
        for (int i = k; i < k + maxPts; i++) {
            windowSum += dp[i];
        }
        
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = windowSum / maxPts;
            windowSum = windowSum - dp[i + maxPts] + dp[i];
        }
        
        return dp[0];
    }
};
