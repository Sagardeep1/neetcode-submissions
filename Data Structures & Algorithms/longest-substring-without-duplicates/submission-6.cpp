class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        unordered_set<char> vis;
        int l = 0, r = 0;
        for(; r < n ; r++) {
            char ch = s[r];
            if (vis.find(ch) != vis.end()) {
                while(s[l] != ch) {
                    vis.erase(s[l]);
                    l++;
                }
                l++;
            }
            else {
                vis.insert(ch);
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
