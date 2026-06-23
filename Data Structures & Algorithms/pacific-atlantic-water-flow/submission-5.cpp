class Solution {

    vector<vector<int>> direc = {{-1,0},{0,1},{1,0},{0,-1}};

    bool isValid(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c, int prev) {
        int n = heights.size(), m = heights[0].size();
        if(r >= 0 && r < n && c >= 0 && c < m && !ocean[r][c] && heights[r][c] >= prev)
            return true;
        return false;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c, int prev) {
        ocean[r][c] = true;
        for(int k=0;k<4;k++) {
            int r_new = r + direc[k][0];
            int c_new = c + direc[k][1];
            if(!isValid(heights,ocean,r_new,c_new,heights[r][c]))
                continue;
            dfs(heights,ocean,r_new,c_new,heights[r][c]);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false));
        vector<vector<bool>> atl(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
            dfs(heights,pac,i,0,0);
        for(int j=1;j<m;j++)
            dfs(heights,pac,0,j,0);
        for(int i=0;i<n;i++)
            dfs(heights,atl,i,m-1,0);
        for(int j=0;j<m-1;j++)
            dfs(heights,atl,n-1,j,0);
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
