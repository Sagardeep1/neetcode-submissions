class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ans = 1;
        map<int,bool> present;
        int ref = -1e9+5;
        for(auto& num:nums) {
            present[num] = true;
        }
        int temp_len = 1;
        for(auto itr:present) {
            if(itr.first == ref+1) {
                temp_len++;
                ans = max(ans,temp_len);
            }
            else
                temp_len = 1;
            ref = itr.first;
        }
        return ans;
    }
};
