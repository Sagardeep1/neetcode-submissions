class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> merge(1001, 0);
        vector<vector<int>> res;
        std::unordered_set<int> single;
        for(const auto& interval : intervals) {
            merge[interval[0]]++;
            merge[interval[1]]--;
            if(interval[0] == interval[1])
                single.insert(interval[0]);
        }

        int sum = 0, left = -1, ind = 0;
        for(; ind <= 1000 ; ind++) {
            if(merge[ind] == 0) {
                if(sum == 0 && single.contains(ind))
                    res.push_back({ind,ind});
                continue;
            }
            if(merge[ind] > 0) {
                if(sum == 0)
                    left = ind;
                sum += merge[ind];
            }
            else {
                sum += merge[ind];
                if(sum == 0)
                    res.push_back({left, ind});
            }
        }
        return res;
    }
};
