class Solution {
public:
    bool isValid(vector<int>& count, int k, int len) {
        int maxFreq = 0;
        for(int i=0 ; i<26 ; i++) {
            maxFreq = max(maxFreq, count[i]);
        }
        if (len - maxFreq <= k)
            return true;
        return false;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> count(26,0);
        int maxlen = 0;
        int l = 0, r = 0;
        for(; r < n ; r++) {
            count[s[r]-'A']++;
            if(isValid(count, k, r-l+1))
                maxlen = max(maxlen, r-l+1);
            else {
                while(l < r && !isValid(count, k, r-l+1)) {
                    count[s[l]-'A']--;
                    l++;
                }
                maxlen = max(maxlen, r-l+1);
            }
        }
        return maxlen;
    }
};
