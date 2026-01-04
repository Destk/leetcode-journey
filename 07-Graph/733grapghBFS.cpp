vector<vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
    int origc = image[sr][sc];
    if(origc == color) return image;
    std::queue<std::pair<int,int>> q{};
    image[sr][sc] = color;
    q.push({sr,sc});
    while(!q.empty()){
        std::pair<int,int> curr = q.front();
        q.pop();
        int row = curr.first;
        int col = curr.second;
        if(row-1 >= 0 && row-1 < image.size() && col >= 0 && col < image[0].size() && image[row-1][col] == origc){
            image[row-1][col] = color;
            q.push({row-1,col});
        }
        if(row+1 >= 0 && row+1 < image.size() && col >= 0 && col < image[0].size() && image[row+1][col] == origc){
            image[row+1][col] = color;
            q.push({row+1,col});
        }
if(row >= 0 && row < image.size() && col-1 >= 0 && col-1 < image[0].size() && image[row][col-1] == origc){
            image[row][col-1] = color;
            q.push({row,col-1});
        }
        if(row >= 0 && row < image.size() && col+1 >= 0 && col+1 < image[0].size() && image[row][col+1] == origc){
            image[row][col+1] = color;
            q.push({row,col+1});
        }
    }
    return image;
}
