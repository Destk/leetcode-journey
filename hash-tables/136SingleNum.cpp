    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        std::unordered_map<int,int> h{};
        for(const auto& el : nums){
            h[el]++;
        }
        for(auto& el : h){
            if(el.second == 1) return el.first;
        }
        return -1;    
    }
