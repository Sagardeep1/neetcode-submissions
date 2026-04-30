class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(mp.contains(nums[i]))
                return {mp[nums[i]],i};
            mp[target-nums[i]] = i;
        }
        return {};
    }
};
