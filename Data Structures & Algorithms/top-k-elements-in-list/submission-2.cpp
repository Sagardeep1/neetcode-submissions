class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num:nums) {
            if(mp.contains(num))
                mp[num]++;
            else mp[num] = 1;
        }
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto itr:mp)
            pq.push({itr.second,itr.first});
        while(k > 0) {
            auto pr = pq.top();
            pq.pop();
            ans.push_back(pr.second);
            k--;
        }
        return ans;
    }
};
