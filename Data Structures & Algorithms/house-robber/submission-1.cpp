class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return dfs(nums,0);
    }

    int dfs(vector<int>& nums, int ind) {
        if(ind >= nums.size())
            return 0;
        if(dp[ind] != -1) 
            return dp[ind];
        return dp[ind] = max(dfs(nums,ind+1), nums[ind] + dfs(nums,ind+2));
    }
};
