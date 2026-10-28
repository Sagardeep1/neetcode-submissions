class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int l = 0, r = 0;
        vector<int> ans;
        for(; r < k ; r++) {
            pq.push({nums[r], r});
        }
        ans.push_back(pq.top().first);
        for(; r < nums.size() ; r++) {
            pq.push({nums[r], r});
            l++;
            while(pq.top().second < l || pq.top().second > r)
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
