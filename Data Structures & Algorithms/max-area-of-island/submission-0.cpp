class Solution {

    bool isValid(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1 || vis[r][c])
            return false;
        return true;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> qu;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(vis[i][j] || grid[i][j] == 0)
                    continue;
                qu.push({i,j});
                vis[i][j] = true;
                int count = 0;
                vector<pair<int, int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
                
                while(!qu.empty()) {
                    count++;
                    auto [r,c] = qu.front();
                    qu.pop();
                    for(auto [dr, dc]: dir) {
                        int _r = r + dr;
                        int _c = c + dc;
                        if(isValid(grid, vis, _r, _c)) {
                            qu.push({_r, _c});
                            vis[_r][_c] = true;
                        }
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
