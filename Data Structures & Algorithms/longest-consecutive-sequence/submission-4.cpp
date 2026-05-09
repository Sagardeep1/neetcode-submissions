class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int,bool> vis;
        for(auto num:nums)
            vis[num] = true;
        int ref = -1e9-5, ans = 0, temp = 0;
        for(auto itr:vis) {
            if(itr.first != ref+1) {
                temp = 0;
            }
            ref = itr.first;
            temp++;
            ans = max(ans,temp);
        }
        return ans;
    }
};
