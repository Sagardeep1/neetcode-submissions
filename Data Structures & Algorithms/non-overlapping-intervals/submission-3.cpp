class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int ans = 0, ref_min = intervals[0][0], ref_max = intervals[0][1];
        for(int i=1 ; i<n ; i++) {
            vector<int> vec = intervals[i];
            if(vec[0] == ref_min) {
                ans++;
                continue;
            }
            if(vec[0] < ref_max) {
                ans++;
                if(vec[1] < ref_max) {
                    ref_min = vec[0];
                    ref_max = vec[1];
                }
            }
            else {
                ref_min = vec[0];
                ref_max = vec[1];
            }
        }
        return ans;
    }
};
