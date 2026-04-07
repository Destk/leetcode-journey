class Solution {
private:
    void countFructs(const std::vector<std::vector<int>>& grid, 
                     std::queue<std::pair<int,int>>& q, 
                     int& fresh) {
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
    }
    
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int,int>> q;
        int fresh = 0;
        countFructs(grid, q, fresh);
        
        int minutes = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int levelSize = q.size();
            bool rottedThisMinute = false;
            
            for (int i = 0; i < levelSize; i++) {
                std::pair<int,int> curr = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int nx = curr.first + dx[d];
                    int ny = curr.second + dy[d];
                    
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                        if (grid[nx][ny] == 1) {
                            grid[nx][ny] = 2;
                            fresh--;
                            q.push({nx, ny});
                            rottedThisMinute = true;
                        }
                    }
                }
            }
            
            if (rottedThisMinute) {
                minutes++;
            }
        }
        
        return (fresh == 0) ? minutes : -1;
    }
};
