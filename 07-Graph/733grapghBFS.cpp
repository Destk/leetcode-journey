vector<vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
    if(image.empty() && image[0].empty()) return image;
    std::queue<std::pair<int,int>> q{};
    q.push({sr, sc});
    int origcolor = image[sr][sc];
    std::vector<std::vector<bool>> visited(image.size(), std::vector<bool>(image[0].size(), false));
    
    while(!q.empty()){
        std::pair<int,int> coord = q.front();
        q.pop();
        int l = coord.first;
        int r = coord.second;
        visited[l][r] = true;
        image[l][r] = color;
        
        // ВВЕРХ
        if (l - 1 >= 0 && l - 1 < image.size() && r >= 0 && r < image[0].size() && 
            image[l-1][r] == origcolor && !visited[l-1][r]) {
            q.push({l-1, r});
        }
        // ВНИЗ
        if (l + 1 >= 0 && l + 1 < image.size() && r >= 0 && r < image[0].size() && 
            image[l+1][r] == origcolor && !visited[l+1][r]) {
            q.push({l+1, r});
        }
        // ВЛЕВО
        if (l >= 0 && l < image.size() && r - 1 >= 0 && r - 1 < image[0].size() && 
            image[l][r-1] == origcolor && !visited[l][r-1]) {
            q.push({l, r-1});
        }
        // ВПРАВО
        if (l >= 0 && l < image.size() && r + 1 >= 0 && r + 1 < image[0].size() && 
            image[l][r+1] == origcolor && !visited[l][r+1]) {
            q.push({l, r+1});
        }
    }
    return image;
}
