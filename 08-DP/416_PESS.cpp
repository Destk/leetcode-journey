class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        if(nums.empty()) return false;
        
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        
        if(total % 2 != 0) return false;
        
        int target = total / 2;
        std::vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) {
                if(dp[j - nums[i]] == 1) {
                    dp[j] = 1;
                }
            }
        }
        
        return dp[target];
    }
};
