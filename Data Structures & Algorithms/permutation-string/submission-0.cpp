class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        int n1 = s1.size(), n2 = s2.size();
        vector<int> count1(26,0), count2(26,0);
        for(char ch:s1)
            count1[ch-'a']++;
        int l = 0, r = 0;
        for(; r < n1 ; r++)
            count2[s2[r]-'a']++;
        if(count1 == count2) return true;
        while(r < n2) {
            count2[s2[l]-'a']--;
            l++; 
            count2[s2[r]-'a']++;
            r++;
            if(count1 == count2)
                return true;
        }
        return false;
    }
};
