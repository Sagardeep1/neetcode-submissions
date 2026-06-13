class Solution {
    vector<vector<int>> ans;
    //vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{}}

    bool isValid(vector<vector<int>>& heights, int r, int c, int prev, 
     vector<vector<bool>>& vis) {
        if(r >= 0 && r < heights.size() && c >= 0 && c < heights[0].size() && 
         heights[r][c] <= prev && !vis[r][c])
            return true;
        return false;
    }

    bool dfs(vector<vector<int>>& heights, int r, int c, int prev, bool& pac_flag, 
     bool& atl_flag, vector<vector<bool>>& vis) {
        if(!isValid(heights,r,c,prev,vis))
            return false;
        vis[r][c] = true;
        if(r == 0 || c == 0)
            pac_flag = true;
        if(r == heights.size()-1 || c == heights[0].size()-1)
            atl_flag = true;
        if(pac_flag && atl_flag)
            return true;
        return dfs(heights,r-1,c,heights[r][c],pac_flag,atl_flag,vis) ||
         dfs(heights,r,c+1,heights[r][c],pac_flag,atl_flag,vis) ||
         dfs(heights,r+1,c,heights[r][c],pac_flag,atl_flag,vis) ||
         dfs(heights,r,c-1,heights[r][c],pac_flag,atl_flag,vis);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                bool pac_flag = false;
                bool atl_flag = false;
                vector<vector<bool>> vis(n,vector<bool>(m,false));
                if(dfs(heights,i,j,INT_MAX,pac_flag,atl_flag,vis))
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
