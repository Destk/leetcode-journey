class Solution {
public:
    void BFS(const vector<vector<int>>& rooms, std::vector<bool>& vis){
        std::queue<int> q{};
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for (int key : rooms[curr]) {
                if (!vis[key]) {
                    vis[key] = true;
                    q.push(key);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::vector<bool> vis(rooms.size(),0);
        BFS(rooms, vis);
        for (bool b : vis) {
        if (!b) return false;
        }
        return true;
    }
};
