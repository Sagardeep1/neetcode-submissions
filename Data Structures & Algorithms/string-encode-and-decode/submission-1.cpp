class Solution {
public:

    string encode(vector<string>& strs) {
        string msg = "";
        for(auto str:strs) {
            int str_len = str.size();
            string s_len = to_string(str_len);
            if(str_len < 10)
                s_len = "00" + s_len;
            else if(str_len < 100)
                s_len =  "0" + s_len;
            msg += (s_len + str);
        }
        return msg;
    }

    vector<string> decode(string s) {
        vector<string> orig_string;
        int ptr = 0;
        while(ptr < s.size()) {
            int len = stoi(s.substr(ptr,3));
            ptr += 3;
            orig_string.push_back(s.substr(ptr,len));
            ptr += len;
        }
        return orig_string;
    }
};
