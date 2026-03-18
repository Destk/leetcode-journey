class Solution {
public:
    int countQuadruplets(std::vector<int>& nums) {
        if(nums.empty()) return 0;
        int count{};
        for(int a = 0; a < nums.size(); a++){
            for(int b = a + 1; b < nums.size(); b++){
                for(int c = b + 1; c < nums.size(); c++){
                    int sum = nums[a] + nums[b] + nums[c];
                    for(int d = c + 1; d < nums.size(); d++){
                        if(nums[d] == sum){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
