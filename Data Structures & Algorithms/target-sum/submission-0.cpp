class Solution {
    vector<vector<int>> dp;
    int totalSum;

public:

    int rec_func(vector<int>& nums, int& target, int ind, int sum) {
        if(ind == nums.size())
            return target == sum;
        if(dp[ind][sum + totalSum] != -1)
            return dp[ind][sum + totalSum];

        dp[ind][sum + totalSum] = rec_func(nums, target, ind+1, sum+nums[ind])
            + rec_func(nums, target, ind+1, sum-nums[ind]);
        return dp[ind][sum + totalSum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp.resize(n, vector<int>(2*totalSum + 1, -1));
        return rec_func(nums,target,0,0);
    }
};
