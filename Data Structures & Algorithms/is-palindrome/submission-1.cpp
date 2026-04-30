class Solution {

    bool isValid(string& str, int ptr) {
        if((str[ptr] >= 'A' && str[ptr] <= 'Z') || (str[ptr] >= 'a' && str[ptr] <= 'z')
        || (str[ptr] >= '0' && str[ptr] <= '9'))
            return true;
        return false;
    }

public:
    bool isPalindrome(string s) {
        int n = s.size();
        int ptr1 = 0, ptr2 = n-1;
        while(ptr1 < ptr2) {
            while(ptr1 < n && !isValid(s, ptr1))
                ptr1++;
            while(ptr2 >= 0 && !isValid(s, ptr2))
                ptr2--;
            if(ptr1 >= n || ptr2 < 0)
                return true;
            if(ptr1 >= ptr2) break;
            if(tolower(s[ptr1]) != tolower(s[ptr2])) break;
            ptr1++;
            ptr2--;
        }
        if(ptr1 >= ptr2) return true;
        return false;
    }
};
