class Solution {

    bool dfs(int numCourses, vector<vector<int>>& adj, vector<bool>& vis, int ind) {
        vis[ind] = true;
        for(int dep:adj[ind]) {
            if(vis[dep]) return false;
            if(!dfs(numCourses,adj,vis,dep)) return false;
        }
        vis[ind] = false;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto vec:prerequisites) {
            adj[vec[0]].push_back(vec[1]);
        }
        vector<bool> vis(numCourses,false);
        for(int i=0;i<numCourses;i++) {
            if(vis[i]) continue;
            if(!dfs(numCourses,adj,vis,i)) return false;
        }
        return true;
    }
};
