int islandPerimeter(vector<vector<int>>& grid) {
    int P{};
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size();j++){
            if(grid[i][j] == 1){
                if(i == 0 || grid[i-1][j] == 0){
                    P++;
                }if(i == grid.size()-1 || grid[i+1][j] == 0){
                    P++;
                }if(j == 0 || grid[i][j-1] == 0){
                    P++;
                }if(j == grid[0].size()-1 || grid[i][j+1] == 0){
                    P++;
                }
            }
        }
    }
    return P;        
}
