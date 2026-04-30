class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        priority_queue<pair<int,int>> pq;
        for(auto num:nums){
            if(freq.count(num) == 0)
                freq[num] = 1;
            else freq[num]++;
        }
        for(auto itr:freq) {
            pq.push({itr.second, itr.first});
        }
        vector<int> ans;
        int count = 0;
        while(!pq.empty()) {
            auto pr = pq.top();
            pq.pop();
            ans.push_back(pr.second);
            count++;
            if(count == k) break;
        }
        return ans;
    }
};
