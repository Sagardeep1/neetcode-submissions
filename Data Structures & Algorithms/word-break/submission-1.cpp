class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n,false);
        for(int i=n-1;i>=0;i--) {
            for(string word : wordDict) {
                int word_sz = word.size();
                if(i + word_sz - 1 >= n) continue;
                if((s.substr(i,word_sz) == word) && (i + word_sz == n || dp[i+word_sz]))
                    dp[i] = true;
            }
        }
        return dp[0]; 
    }
};
