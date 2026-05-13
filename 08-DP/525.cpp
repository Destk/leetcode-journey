class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        if(nums.empty()) return 0;
        std::unordered_map<int,int> map{};
        int curr{0}, maxL{0};
        map[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            int val = (nums[i] == 0 ? -1 : 1);
            curr+=val;
            if(map.count(curr)){
                maxL = std::max(maxL, (i + 1) - map[curr]);
            }else{
                map[curr] = i+1;
            }
        }
        return maxL;
    }
};
