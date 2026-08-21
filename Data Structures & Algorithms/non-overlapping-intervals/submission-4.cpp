class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int ans = 0, ref_max = intervals[0][1];
        for(int i=1 ; i<n ; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start >= ref_max) 
                ref_max = end;
            else {
                ans++;
                ref_max = min(ref_max,end);
            }
        }
        return ans;
    }
};
