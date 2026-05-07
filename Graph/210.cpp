class Solution {
public:
    std::vector<int> BFS(int numCourses, std::vector<std::vector<int>>& prerequisites, std::vector<std::vector<int>>& adj){
        std::vector<int> indegree(numCourses, 0);
        for(auto el : prerequisites){
            int a = el[0];
            indegree[a]++;
        }
        std::queue<int> q{};
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }
        std::vector<int> order{};
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            for(auto vec : adj[curr]){
                indegree[vec]--;
                if(indegree[vec]==0){
                    q.push(vec);
                }
            }
        }
        if(order.size() == numCourses) return order;
        return {};
    }
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for(auto vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        return BFS(numCourses, prerequisites, adj);
    }
};
