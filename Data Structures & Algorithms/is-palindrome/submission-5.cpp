class Solution {
public:
    bool isPalindrome(string s) {
        int ptr1=0, ptr2 = s.size()-1;
        while(ptr1 < ptr2) {
            while(ptr1 < s.size() && !isalnum(s[ptr1])) {
                ptr1++;
            }
            while(ptr2 >= 0 && !isalnum(s[ptr2])) {
                ptr2--;
            }
            if(ptr1 > ptr2) break;
            if(tolower(s[ptr1]) != tolower(s[ptr2])) return false;
            ptr1++;
            ptr2--;
        }
        return true; 
    }
};
