int numIslands(vector<vector<char>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int countis = 0;
    std::queue<std::pair<int,int>> q;
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                countis++;
                q.push({i,j});
                
                while(!q.empty()){
                    std::pair<int, int> curr = q.front();
                    int ci = curr.first;
                    int cj = curr.second;
                    q.pop();
                    visited[ci][cj] = true;
                    
                    // ⬆️ верхний
                    int nci = ci - 1;
                    int ncj = cj;
                    if(nci >= 0 && nci < grid.size() && ncj >= 0 && ncj < grid[0].size() && 
                       grid[nci][ncj] == '1' && !visited[nci][ncj]){
                        q.push({nci,ncj});
                        visited[nci][ncj] = true;
                    }
                    
                    // ⬇️ нижний
                    nci = ci + 1;
                    ncj = cj;
                    if(nci >= 0 && nci < grid.size() && ncj >= 0 && ncj < grid[0].size() && 
                       grid[nci][ncj] == '1' && !visited[nci][ncj]){
                        q.push({nci,ncj});
                        visited[nci][ncj] = true;
                    }
                    
                    // ⬅️ левый
                    nci = ci;
                    ncj = cj - 1;
                    if(nci >= 0 && nci < grid.size() && ncj >= 0 && ncj < grid[0].size() && 
                       grid[nci][ncj] == '1' && !visited[nci][ncj]){
                        q.push({nci,ncj});
                        visited[nci][ncj] = true;
                    }
                    
                    // ➡️ правый
                    nci = ci;
                    ncj = cj + 1;
                    if(nci >= 0 && nci < grid.size() && ncj >= 0 && ncj < grid[0].size() && 
                       grid[nci][ncj] == '1' && !visited[nci][ncj]){
                        q.push({nci,ncj});
                        visited[nci][ncj] = true;
                    }
                } // ✅ while закрывается здесь
            }
        }
    }
    return countis;
}
