class Solution {
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& tmp, int target, int ind) {
        if(target == 0) {
            ans.push_back(tmp);
            return;
        }
        if(ind == nums.size() || target-nums[ind] < 0)
            return;
        tmp.push_back(nums[ind]);
        backtrack(nums,tmp,target-nums[ind],ind);
        tmp.pop_back();
        backtrack(nums,tmp,target,ind+1);
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        backtrack(nums,tmp,target,0);
        return ans;
    }
};
