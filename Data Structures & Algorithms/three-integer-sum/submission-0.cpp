class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;) {
            int l=i+1, r=n-1, target = -nums[i];
            while(l<r) {
                int sum = nums[l] + nums[r];
                if(sum == target) {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l-1] == nums[l])
                        l++;
                    while(l < r && nums[r+1] == nums[r])
                        r--;
                }
                else if(sum < target) {
                    l++;
                    while(l < r && nums[l-1] == nums[l])
                        l++;
                }
                else {
                    r--;
                    while(l < r && nums[r+1] == nums[r])
                        r--;
                }
            }
            i++;
            while(i < n-2 && nums[i-1] == nums[i])
                    i++;
        }
        return ans;
    }
};
