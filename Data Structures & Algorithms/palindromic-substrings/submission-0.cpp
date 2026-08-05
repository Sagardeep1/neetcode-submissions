class Solution {
    int find_pal_len(string& s, int ind, int flag) {            // flag 0 for odd len palindromes, flag 1 for even len palindromes
        int ptr_l, ptr_r, res = 0;
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
            res++;
        }
        return res;
    }

public:
    int countSubstrings(string s) {
        int n = s.size(), ans = n;
        for(int i=0;i<n;i++) {
            ans += find_pal_len(s,i,0);
            ans += find_pal_len(s,i,1);
        }
        return ans;
    }
};
