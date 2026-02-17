class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size() == 1) return {nums};
        std::vector<std::vector<int>> res{};
        std::vector<int> curr{};
        std::vector<bool> use(nums.size(), false);
        std::function<void()> func;
        func = [&] (){
            if(curr.size() == nums.size()){
                res.push_back(curr);
                return;
            }
            for(size_t i = 0; i < nums.size(); i++){
                if(!use[i]){
                    curr.push_back(nums[i]);
                    use[i] = true;
                    func();
                    use[i] = false;
                    curr.pop_back();
                }
            }
        };
        func();
        return res;
    }
};
