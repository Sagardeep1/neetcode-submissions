class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        int ind = 0;
        for(; ind < k ; ind++) {
            pq.push({nums[ind], ind});
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        while(ind < n) {
            pq.push({nums[ind], ind});
            while(pq.top().second <= ind - k)
                pq.pop();
            ans.push_back(pq.top().first);
            ind++;
        }
        return ans;
    }
};
