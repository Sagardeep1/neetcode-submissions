class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r, ans = 0;
        unordered_map<char,bool> present;
        for(r=0;r<s.size();r++) {
            char ch = s[r];
            if(present.contains(ch)) {
                ans = max(ans,r-l);
                while(present.contains(ch)) {
                    present.erase(s[l]);
                    l++;
                }
            }
            present[ch] = true;
        }
        ans = max(ans,r-l);
        return ans;
    }
};
