class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int ans = 0, prevEnd = intervals[0][1];
        for(int i=1 ; i<n ; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start < prevEnd) 
                ans++;
            else {
                prevEnd = end;
            }
        }
        return ans;
    }
};
