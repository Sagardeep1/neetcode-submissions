class Solution {
    vector<vector<int>> dp;

    int rec_func(string& text1, string& text2, int ind1, int ind2) {
        int n1 = text1.size(), n2 = text2.size();
        if(ind1 == n1 || ind2 == n2) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2])
            dp[ind1][ind2] = 1 + rec_func(text1,text2,ind1+1,ind2+1);
        else
            dp[ind1][ind2] = max(rec_func(text1,text2,ind1+1,ind2),
             rec_func(text1,text2,ind1,ind2+1));
        return dp[ind1][ind2];
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        dp.resize(n1, vector<int>(n2, -1));
        return rec_func(text1,text2,0,0);
    }
};
