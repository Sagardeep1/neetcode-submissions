class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r, ans = 0;
        unordered_map<char,int> present;
        for(r=0;r<s.size();r++) {
            char ch = s[r];
            if(present.count(ch)) {
                cout<<r<<'*'<<l<<endl;
                ans = max(ans,r-l);
                l = max(l,present[ch]+1);
            }
            present[ch] = r;
        }
        ans = max(ans,r-l);
        return ans;
    }
};
