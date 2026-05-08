class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> rhs(n,1);
        for(int i=n-2;i>=0;i--) {
            rhs[i] = rhs[i+1] * nums[i+1];
        }
        int lhs = 1;
        vector<int> ans(n);
        ans[0] = rhs[0];
        for(int i=1;i<n;i++) {
            lhs *= nums[i-1];
            ans[i] = lhs * rhs[i];
        }
        return ans;
    }
};
