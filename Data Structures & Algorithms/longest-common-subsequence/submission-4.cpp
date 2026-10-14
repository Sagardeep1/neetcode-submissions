class Solution {
    int max_len = 0;
    vector<vector<int>> dp;

public:
    int recursive_func(string& text1, string& text2, int ind1, int ind2) {
        int n1 = text1.size(), n2 = text2.size();
        if (ind1 >= n1 || ind2 >= n2)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int ans = 0;
        if (text1[ind1] == text2[ind2])
            ans = max(ans, 1 + recursive_func(text1, text2, ind1+1, ind2+1));
        else
            ans = max(ans, max(recursive_func(text1, text2, ind1+1, ind2), 
            recursive_func(text1, text2, ind1, ind2+1)));
        max_len = max(max_len, ans);
        return dp[ind1][ind2] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        dp.resize(n1, vector<int>(n2, -1));
        recursive_func(text1, text2, 0, 0);
        return max_len;
    }
};
