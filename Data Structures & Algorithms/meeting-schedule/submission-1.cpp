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
        int n = intervals.size();
        int prevEnd = intervals[0].end, sum = 0;
        map<int, int> mp;
        for(auto obj : intervals) {
            mp[obj.start]++;
            mp[obj.end]--;
        }
        for(const auto& [ind, count] : mp) {
            sum += count;
            if(sum > 1) return false;
        }
        return true;
    }
};
