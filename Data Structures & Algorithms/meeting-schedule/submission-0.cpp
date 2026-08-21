/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if(a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });
        int n = intervals.size();
        int prevEnd = intervals[0].end, ans = 0;
        for(int i = 1 ; i<n ; i++) {
            if(intervals[i].start < prevEnd)
                return false;
            prevEnd = intervals[i].end;
        }
        return true;
    }
};
