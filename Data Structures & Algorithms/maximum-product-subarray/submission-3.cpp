class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curMax, curMin, ans;
        curMax = ans = curMin = nums[0];
        for(int i=1;i<n;i++) {
            int max_ = max(nums[i], max(nums[i] * curMax, nums[i] * curMin));
            int min_ = min(nums[i], min(nums[i] * curMax, nums[i] * curMin));
            curMax = max_;
            curMin = min_;
            ans = max(ans,curMax);
        }
        return ans;
    }
};
