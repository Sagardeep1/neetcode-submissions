#define MAX 1005
#define MIN -5

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int max_lim = intervals[0][1], min_lim = intervals[0][0];
        for(int i = 1; i < n ; i++) {
            if(max_lim < intervals[i][0]) {
                res.push_back({min_lim, max_lim});
                max_lim = intervals[i][1], min_lim = intervals[i][0];
                continue;
            }
            max_lim = max(max_lim, intervals[i][1]);
        }
        res.push_back({min_lim, max_lim});
        return res;
    }
};
