class Solution {

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        int n = adj.size();
        vis[node] = true;
        for(int neigh:adj[node]) {
            if(vis[neigh]) continue;
            dfs(neigh,adj,vis);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        for(int i=0;i<n;i++) {
            if(vis[i]) continue;
            count++;
            dfs(i,adj,vis);
        }
        return count;
    }
};
