class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        int i, j;
        for(j=0;j<n;j++)
            dp[j] = 1;
        for(i = m-2 ; i >= 0; i--) {
            vector<int> temp(n,1);
            int right = 1;
            for(j = n-2 ; j >= 0 ; j--) {
                temp[j] = right + dp[j];
                right = temp[j];
            }
            dp = temp;
        }
        return dp[0];
    }
};
