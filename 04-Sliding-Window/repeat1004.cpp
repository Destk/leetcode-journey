class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int zcount{0};
        int l{0};
        int maxL{};
        for(int r = 0; r < nums.size();r++){
            if(nums[r] == 0) zcount++;
            while(zcount > k && l <= r){
                if(nums[l] == 0) zcount--;
                l++;
            }
            maxL = std::max(maxL, r - l + 1);
        }
        return maxL;
    }
};
