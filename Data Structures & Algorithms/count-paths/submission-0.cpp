class Solution {
    vector<vector<int>>dp;

    int rec_func(int r, int c) {
        int m = dp.size(), n = dp[0].size();
        if(r >= m || c >= n) return 0;
        if(r == m-1 && c == n-1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        dp[r][c] = rec_func(r,c+1) + rec_func(r+1,c);
        return dp[r][c];
    }

public:
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n,-1));
        return rec_func(0,0);
    }
};
