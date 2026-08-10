class Solution {
    vector<int> dp;

    bool rec_func(string& s, vector<string>& wordDict, int ind) {
        if(ind == s.size()) return true;
        else if(ind > s.size()) return false;
        if(dp[ind] != -1) {
            if(dp[ind] == 1)
                return true;
            return false;
        }
        for(string word:wordDict) {
            int word_sz = word.size();
            if(ind + word_sz - 1 >= s.size()) continue;
            if(s.substr(ind,word_sz) == word) {
                if(rec_func(s,wordDict, ind + word_sz)) {
                    dp[ind] = 1;
                    return true;
                }
            }
        }
        dp[ind] = 0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp.resize(n,-1);
        if(rec_func(s,wordDict,0))
            return true;
        return false;
    }
};
