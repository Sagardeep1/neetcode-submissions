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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        int prevEnd = intervals[0].end, sum = 0, ans = 1;
        map<int, int> mp;
        for(auto obj : intervals) {
            mp[obj.start]++;
            mp[obj.end]--;
        }
        for(const auto& [ind, count] : mp) {
            sum += count;
            ans = max(ans, sum);
        }
        return ans;
    }
};
