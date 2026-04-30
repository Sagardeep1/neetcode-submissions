class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count_s(26,0), count_t(26,0);
        for(char ch:s)
            count_s[ch-'a']++;
        for(char ch:t)
            count_t[ch-'a']++;
        for(int i=0;i<26;i++)
            if(count_s[i] != count_t[i])
                return false;
        return true;
    }
};
