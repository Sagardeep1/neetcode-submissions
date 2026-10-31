class Solution {
    vector<vector<int>> dp;

    int rec_func(vector<int>& coins, int target, int sum, int ind) {
        if (ind == coins.size()) {
            if (sum == target)
                return 1;
            return 0;
        }
        if (sum > target)
            return 0;
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        int count = 0, addn = 0;
        while(sum + addn <= target) {
            count += rec_func(coins, target, sum+addn, ind+1);
            addn += coins[ind];
        }
        return dp[ind][sum] = count;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n, vector<int>(amount+5, -1));
        int ans = rec_func(coins, amount, 0, 0);
        return ans;
    }
};
