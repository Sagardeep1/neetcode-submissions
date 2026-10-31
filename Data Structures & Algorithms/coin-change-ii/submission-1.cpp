class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+5, 0));
        dp[0][0] = 1;
        for(int i=1 ; i<=n ; i++) {
            for(int j = 0 ; j <= amount ; j++) {
                int subtrn = 0, count = 0;
                while(j - subtrn >= 0) {
                    count += dp[i-1][j-subtrn];
                    subtrn += coins[i-1];
                }
                dp[i][j] = count;
            }
        }
        return dp[n][amount];
    }
};
