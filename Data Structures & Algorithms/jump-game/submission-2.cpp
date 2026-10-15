class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), lim = nums[0];
        int ind = 0;
        if(n == 1) return true;
        while(ind <= lim) {
            lim = max(lim, ind + nums[ind]);
            ind++;
            if(lim >= n-1) break;
        }
        if(lim < n-1)
            return false;
        return true;
    }
};
