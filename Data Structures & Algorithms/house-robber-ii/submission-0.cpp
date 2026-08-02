class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(helper(vector<int>(nums.begin(), nums.end()-1)), helper(vector<int>(nums.begin()+1, nums.end())));
    }

    int helper(vector<int> nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int n_2 = nums[0], n_1 = max(nums[0],nums[1]);
        for(int i=2;i<n;i++) {
            int sum = max(nums[i]+n_2, n_1);
            n_2 = n_1;
            n_1 = sum;
        }
        return n_1;
    }
};
