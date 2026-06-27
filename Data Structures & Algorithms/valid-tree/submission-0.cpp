class Solution {

    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int node, int prev) {
        if(vis[node])
            return false;
        vis[node] = true;
        for(auto neigh:adj[node]) {
            if(neigh == prev) continue;
            if(!dfs(adj,vis,neigh,node))
                return false;
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);   
        }
        vector<bool> vis(n,false);
        if(!dfs(adj,vis,0,-1))
            return false;
        for(int i=0;i<n;i++)
            if(!vis[i]) return false;
        return true;
    }
};
