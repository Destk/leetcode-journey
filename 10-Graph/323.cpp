for(auto vec : edge){
     int a = vec[0];
     int b = vec[1];
    adj[b].push_back(a);
}

class Solution {
public:
    int CountCom(int n, const std::vector<std::vector<int>>& adj, std::vector<bool>& vis){
        int count{0};
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                BFS(i, adj, vis)
            }
        }
        return count;
    }
    void BFS(int st, const std::vector<std::vector<int>>& adj, std::vector<bool>& vis){
        int count{0};
        std::queue<int> q{};
        q.push(st);
        vis[st] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto neib : adj[curr]){
                if(!vis[neib]){
                    q.push(neib);
                    vis[neib] = true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        for(auto vec : edges){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            adj[a].push_back(b);
        }
        std::vector<bool> vis(n, false);
        return CountCom(n, adj, vis);
    }
};