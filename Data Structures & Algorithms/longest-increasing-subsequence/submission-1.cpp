class Solution {
    vector<int> dp;
    int ans = 1;

    int rec_func(vector<int>& nums, int ind) {
        if(dp[ind] != -1)
            return dp[ind];
        int maxLen = 0;
        for(int j=ind+1;j<nums.size();j++) {
            if(nums[ind] < nums[j])
                maxLen = max(maxLen, rec_func(nums,j));
        }
        dp[ind] = maxLen + 1;
        ans = max(ans,dp[ind]);
        return dp[ind];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        for(int i=0;i<n;i++)
            rec_func(nums,i);
        return ans;
    }
};
