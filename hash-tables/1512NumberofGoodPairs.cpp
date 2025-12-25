int numIdenticalPairs(vector<int>& nums) {
    std::unordered_map<int,int> m{};
    int maxpair{};
    for(auto& it : nums){
        maxpair+=m[it];
        m[it]++;
    }
    return maxpair;
}
