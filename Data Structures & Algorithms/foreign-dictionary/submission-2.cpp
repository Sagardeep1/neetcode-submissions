class Solution {
    unordered_map<char,vector<char>> adj;
    unordered_map<char,bool> vis;
    string ans = "";

    bool dfs(char cur) {
        if(vis.find(cur) != vis.end())
            return vis[cur];
        vis[cur] = true;
        for(char ch:adj[cur]) {
            if(dfs(ch))
                return true;
        }
        vis[cur] = false;
        ans.push_back(cur);
        return false;
    }

public:
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1)
            return words[0];
        int n = words.size();
        for(int i=0;i<n-1;i++) {
            int ind1 = 0, ind2 = 0;
            string s1 = words[i], s2 = words[i+1];
            while(ind1 < s1.size() && ind2 < s2.size()) {
                if(s1[ind1] != s2[ind2]) break;
                ind1++;ind2++;
            }
            if(ind1 == s1.size() || ind2 == s2.size()) {
                if(s1.size() > s2.size()) return "";
                continue;
            }
            adj[s1[ind1]].push_back(s2[ind2]);
        }
        for(auto word:words) {
            for(char ch:word) {
                //if(vis.find(ch) != vis.end()) continue;
                if(dfs(ch)) {
                    cout<<'*';
                    return "";
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
