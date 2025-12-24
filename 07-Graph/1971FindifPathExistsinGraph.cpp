bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    std::vector<std::vector<int>> adj(n);
    for(auto j : edges){
        int u = j[0], v = j[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::queue<int> q;
    std::vector<bool> visited(n,false);
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == destination){
            return true;
        }for(int neib : adj[curr]){
            if(!visited[neib]){
                q.push(neib);
                visited[neib] = true;
            }
        }
    }
    return false;       
}
