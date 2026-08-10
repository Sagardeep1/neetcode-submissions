class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        vector<int> dp_len(n,0);
        dp_len[0] = 1;
        for(int i=1;i<n;i++) {
            int maxLen = 0;
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i])
                    maxLen = max(maxLen, dp_len[j]);
            }
            dp_len[i] = maxLen + 1;
            ans = max(ans, dp_len[i]);
        }
        return ans;
    }
};
