class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> anagram;
        for(string str:strs) {
            vector<int> count(26,0);
            for(char ch:str)
                count[ch-'a']++;
            anagram[count].push_back(str);
        }
        vector<vector<string>> ans;
        for(const auto& itr:anagram) {
            ans.push_back(itr.second);
        }
        return ans;
    }
};
