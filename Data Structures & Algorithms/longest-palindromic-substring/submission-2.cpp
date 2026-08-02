class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), resLen = 1;
        string result = "";
        result += s[0];
        int ptr_l = 0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int i=n-1; i >= 0 ; i--) {
            for(int j=i ; j < n; j++) {
                if (s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if(resLen < j-i+1) {
                        resLen = j-i+1;
                        ptr_l = i;
                    }
                }
            }
        }
        if(resLen > 1)
            result = s.substr(ptr_l, resLen);
        return result;
    }
};
