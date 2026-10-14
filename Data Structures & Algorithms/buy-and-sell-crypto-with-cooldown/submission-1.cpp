class Solution {

    int rec_func(vector<int>& prices, vector<vector<int>>& dp, int day, int buy) {
        if (day >= prices.size())
            return 0;
        if (dp[day][buy] != -1)
            return dp[day][buy];
        int ans1 = 0, ans2 = 0;
        if (buy == 1) {
            int v_buy = -prices[day] + rec_func(prices, dp, day+1, 0);
            int v_moved = rec_func(prices, dp, day+1, 1);
            ans1 = max(v_buy, v_moved);
        }
        else {
            int v_sold = prices[day] + rec_func(prices, dp, day+2, 1);
            int v_moved = rec_func(prices, dp, day+1, 0);
            ans2 = max(v_sold, v_moved);
        }
        return dp[day][buy] = max(ans1, ans2);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));        // 0 - cannot buy, 1 - can buy
        rec_func(prices, dp, 0, 1);
        return max(dp[0][0], dp[0][1]);
    }
};
