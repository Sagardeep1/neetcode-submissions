class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        /// -nums[i] = nums[j] + nums[k]
        for(int i=0;i<n-2;) {
            int j=i+1, k = n-1;
            while(j < k) {
                int sum = nums[j] + nums[k];
                if(sum == -nums[i]) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j+1 < n && nums[j] == nums[j+1])
                        j++;
                    while(k-1 > i && nums[k] == nums[k-1])
                        k--;
                    j++;k--;
                }
                else if(sum < -nums[i]) {
                     while(j+1 < n && nums[j] == nums[j+1])
                        j++;
                    j++;
                }
                else {
                    while(k-1 > i && nums[k] == nums[k-1])
                        k--;
                    k--;
                }
            }
            while(i < n-3 && nums[i] == nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};
