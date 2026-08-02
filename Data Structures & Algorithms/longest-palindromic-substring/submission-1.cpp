class Solution {
public:
    int ptr_l, ptr_r;

    int find_pal_len(string& s, int ind, int flag) {            // flag 0 for odd len palindromes, flag 1 for even len palindromes
        if(flag == 0) {
            ptr_l = ind-1, ptr_r = ind+1;
        }
        else {
            ptr_l = ind, ptr_r = ind+1;
        }
        while(ptr_l >= 0 && ptr_r < s.size()) {
            if(s[ptr_l] != s[ptr_r])
                break;
            ptr_l--;
            ptr_r++;
        }
        ptr_l++;
        ptr_r--;
        return ptr_r - ptr_l + 1;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int resLen = 1;
        string result = "";
        result += s[0];
        for(int i=0;i<n;i++) {
            int pal_len = find_pal_len(s,i,0);
            if(resLen < pal_len) {
                result = s.substr(ptr_l, ptr_r - ptr_l + 1);
                resLen = pal_len;
            }
            pal_len = find_pal_len(s,i,1);
            if(resLen < pal_len) {
                result = s.substr(ptr_l, ptr_r - ptr_l + 1);
                resLen = pal_len;
            }
        }
        return result;
    }
};
