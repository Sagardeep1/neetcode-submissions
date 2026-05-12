class Solution {

    bool freq_match(unordered_map<char,int>& count_s, unordered_map<char,int>& count_t) {
        for(auto itr:count_t) {
            char ch = itr.first;
            if(!count_s.count(ch) || count_s[ch] < count_t[ch])
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count_s, count_t;
        int l=0, ans = 1005;
        string sub_str = "";
        for(char ch:t)
            count_t[ch]++;
        for(int r=0;r<s.size();r++) {
            count_s[s[r]]++;
            while(freq_match(count_s,count_t)) {
                //cout<<l<<'*'<<r<<endl;
                if(ans > r-l+1) {
                    ans = r-l+1;
                    sub_str = s.substr(l,r-l+1);
                }
                count_s[s[l]]--;
                l++;
            }
        }
        if(ans == 1005) return "";
        return sub_str;
    }
};
