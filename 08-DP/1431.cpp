class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC = 0;
        for (int c : candies) {
            maxC = max(maxC, c);
        }
        
        vector<bool> res;
        for (int c : candies) {
            res.push_back(c + extraCandies >= maxC);
        }
        return res;
    }
};
