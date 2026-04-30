#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str:strs) {
            ans += to_string(str.length());
            ans += '#';
            ans += str;
        }
        cout<<ans;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int ptr = 0;
        while(ptr < s.length()) {
            string len = "";
            while(s[ptr] != '#') {
                len += s[ptr];
                ptr++;
            }
            ptr++;
            int str_len = stoi(len);
            ans.push_back(s.substr(ptr,str_len));
            ptr += str_len; 
        }
        return ans;
    }
};
