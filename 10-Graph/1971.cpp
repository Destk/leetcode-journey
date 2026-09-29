class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::pair<int,int> core{edges[0][0], edges[0][1]};
        int count{0};
        for(auto vec : edges){
            for(auto el : vec){
                if(el == core.first) count++;
            }
        }
        return (count >= 2 ? core.first : core.second);
    }
};
