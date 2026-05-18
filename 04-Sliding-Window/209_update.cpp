class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left{0};
        int sum{0};
        int Mlen = nums.size()+1;
        for(int right = 0; right < nums.size();right++){
            sum+=nums[right];
            while(sum >= target && left <= right){
                Mlen = std::min(Mlen, right -left + 1);
                sum -=nums[left];
                left++;
            }
        }
        return (Mlen == nums.size()+1 ? 0 : Mlen);
    }
};
