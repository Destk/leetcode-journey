class NumMatrix {
private:
    std::vector<std::vector<int>> pref;
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        pref.resize(matrix.size()+1, std::vector<int>(matrix[0].size()+1,0));
        for(int i = 1; i <= matrix.size(); i++){
            for(int j = 1; j <= matrix[0].size(); j++){
                pref[i][j] = matrix[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2+1][col2+1] - pref[row1][col2+1] - pref[row2+1][col1] + pref[row1][col1];
    }
};

