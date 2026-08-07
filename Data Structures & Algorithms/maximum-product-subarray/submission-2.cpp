class Solution {
public:
    int ans = INT_MIN;

    void calc_max(vector<int>& nums, int l, int r, int pro) {
        if(l > r) return;
        if(pro > 0) {
            ans = max(ans,pro);
            return;
        }
        int pro_neg = 1, ind;
        for(ind=l;ind<=r;ind++) {
            pro_neg *= nums[ind];
            if(nums[ind] < 0) break;
        }
        if(ind != r) 
            ans = max(ans, pro/pro_neg);
        pro_neg = 1;
        for(ind=r;ind>=l;ind--) {
            pro_neg *= nums[ind];
            if(nums[ind] < 0) break;
        }
        if(ind != l) 
            ans = max(ans, pro/pro_neg);
        return;
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size(), pro = 1;
        if(n == 1) return nums[0];
        int l = 0, r, max_ele = -15;
        for(r=0;r<n;r++) {
            max_ele = max(max_ele, nums[r]);
            if(nums[r] == 0) {
                calc_max(nums,l,r-1,pro);
                l = r+1;
                pro = 1;
                continue;
            }
            pro *= nums[r];
        }
        calc_max(nums,l,r-1,pro);
        ans = max(ans, max_ele);
        return ans;
    }
};
