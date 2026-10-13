class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int new_max = newInterval[1];
        int new_min = newInterval[0];
        int n = intervals.size();
        for(int i=0;i<n;i++) {
            if(intervals[i][1] < new_min) {
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0] > new_max) {
                res.push_back({new_min, new_max});
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            }
            else {
                new_min = min(new_min, intervals[i][0]);
                new_max = max(new_max, intervals[i][1]);
            }
        }
        res.push_back({new_min,new_max});
        return res;
    }
};
