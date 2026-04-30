class Solution {

    bool isValid(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }

public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l < r) {
            while(l < r && !isValid(s[l]))
                l++;
            while(r > l && !isValid(s[r]))
                r--;
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};
