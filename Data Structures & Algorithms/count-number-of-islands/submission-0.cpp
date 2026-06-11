class Solution {

    bool isValid(vector<vector<char>>& grid, int r, int c) {
        if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && 
        grid[r][c] == '1')
            return true;
        return false;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(!isValid(grid,r,c))
            return;
        grid[r][c] = '0';
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
