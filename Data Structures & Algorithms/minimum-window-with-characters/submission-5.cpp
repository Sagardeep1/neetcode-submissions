class Solution {

    bool count_check(unordered_map<char,int>& count_s, unordered_map<char,int>& count_t) {
        for(auto i:count_t) {
            if(count_s[i.first] < i.second) return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count_s, count_t;
        int ans = INT_MAX;
        int end_l, end_r;
        if(t.size() > s.size())
            return "";
        for(char ch:t)
            count_t[ch]++;
        int l = 0, r = 0;
        while(r < s.size()) {
            count_s[s[r]]++;
            while(count_check(count_s, count_t)) {
                if(ans > r-l+1) {
                    ans = r-l+1;
                    end_l = l, end_r = r;
                }
                count_s[s[l]]--;
                l++;
            }
            r++;
        }
        cout<<ans;
        if(ans == INT_MAX)
            return "";
        return s.substr(end_l, ans);
    }
};
