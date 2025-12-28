int numEnclaves(vector<vector<int>>& grid) {
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    std::queue<std::pair<int,int>> q{};
    int maxenclaves{};
    int S = grid.size();
    int T = grid[0].size();
    for(int i = 0; i < S; i++){
        if(grid[i][0] == 1){
            q.push({i,0});
            visited[i][0] = true;
        }
        if(grid[i][T-1] == 1){
            q.push({i,T-1});
            visited[i][T-1] = true;
        }
    }for(int j = 0; j < T; j++){
        if(grid[0][j] == 1){
            q.push({0,j});
            visited[0][j] = true;
        }if(grid[S-1][j] == 1){
            q.push({S-1,j});
            visited[S-1][j] = true;
        }
    }
    while(!q.empty()){
        std::pair<int,int> curr = q.front();
        q.pop();
        int l = curr.first;
        int r = curr.second;
        if(l-1 >= 0){
            if(grid[l-1][r] == 1 && !visited[l-1][r]){
                visited[l-1][r] = true;
                q.push({l-1,r});
            }
        }
        if(l+1 < S){
            if(grid[l+1][r] == 1 && !visited[l+1][r]){
                visited[l+1][r] = true;
                q.push({l+1,r});
            }
        }
        if(r-1 >= 0){
            if(grid[l][r-1] == 1 && !visited[l][r-1]){
                visited[l][r-1] = true;
                q.push({l,r-1});
            }
        }
        if(r+1 < T){
            if(grid[l][r+1] == 1 && !visited[l][r+1]){
                visited[l][r+1] = true;
                q.push({l,r+1});
            }
        }
    }
    for(int i = 0; i < S; i++){
        for(int j = 0; j < T; j++){
            if(grid[i][j] == 1 && visited[i][j] == false){
                maxenclaves++;
            }
        }
    }
    return maxenclaves;
}
