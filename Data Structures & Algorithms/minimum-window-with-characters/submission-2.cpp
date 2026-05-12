class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count_s, count_t;
        int l=0, ans = 1005, have=0;
        pair<int,int> ends = {-1,-1};
        for(char ch:t)
            count_t[ch]++;
        for(int r=0;r<s.size();r++) {
            count_s[s[r]]++;
            if(count_t.count(s[r]) && count_s[s[r]] == count_t[s[r]])
                have++;
            while(have == count_t.size()) {
                //cout<<l<<'*'<<r<<endl;
                if(ans > r-l+1) {
                    ans = r-l+1;
                    ends = {l,r};
                }
                count_s[s[l]]--;
                if(count_t.count(s[l]) && count_s[s[l]] < count_t[s[l]])
                    have--;
                l++;
            }
        }
        if(ans == 1005) return "";
        return s.substr(ends.first, ans);
    }
};
