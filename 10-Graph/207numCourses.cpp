class Solution {
public:
    bool BFS(const std::vector<std::vector<int>>& prerequisites,const std::vector<std::vector<int>>& adj,int numCourses){
        std::vector<int> indegree(numCourses, 0);
        for(auto el : prerequisites){
            int a = el[0];
            indegree[a]++;
        }
        std::queue<int> q{};
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }
        int countvis{0};
        while(!q.empty()){
            int curr = q.front();
            countvis++;
            q.pop();
            for(auto el : adj[curr]){
                indegree[el]--;
                if(indegree[el] == 0) q.push(el);
            }
        }
        return (countvis == numCourses ? true : false);
    }
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for(auto vec :prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        return BFS(prerequisites, adj, numCourses);
    }
};