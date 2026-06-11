class Solution {

    bool isValid(vector<vector<char>>& grid, int r, int c) {
        if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && 
        grid[r][c] == '1')
            return true;
        return false;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<int> x_coord = {0,1,0,-1};
        vector<int> y_coord = {1,0,-1,0};
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    queue<pair<int,int>> qu;
                    grid[i][j] = '0';
                    qu.push({i,j});
                    while(!qu.empty()) {
                        auto [r,c] = qu.front();
                        qu.pop();
                        for(int k=0;k<4;k++) {
                            int x = r + x_coord[k];
                            int y = c + y_coord[k];
                            if(!isValid(grid,x,y)) continue;
                            qu.push({x,y});
                            grid[x][y] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};
