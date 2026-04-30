class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        vector<vector<int>> freq_sort(n+1);
        for(auto num:nums){
            if(!freq.count(num))
                freq[num] = 1;
            else freq[num]++;
        }
        for(auto itr:freq) {
            freq_sort[itr.second].push_back(itr.first);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--) {
            for(auto num:freq_sort[i]) {
                ans.push_back(num);
                if(ans.size() == k) break;
            }
            if(ans.size() == k) break;
        }
        return ans;
    }
};