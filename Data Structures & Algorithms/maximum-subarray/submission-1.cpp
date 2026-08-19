class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN, minsum = 0;
        int ans = INT_MIN, sum = 0;
        for(int num : nums) {
            sum += num;
            ans = max(ans, sum - minsum);
            minsum = min(0,min(minsum, sum));
        }
        return ans;
    }
};
