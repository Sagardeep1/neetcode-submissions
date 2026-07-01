class Solution {
    unordered_map<char,vector<char>> adj;
    string ans = "";

    // bool dfs(char cur) {
    //     if(vis.find(cur) != vis.end())
    //         return vis[cur];
    //     vis[cur] = true;
    //     for(char ch:adj[cur]) {
    //         if(dfs(ch))
    //             return true;
    //     }
    //     vis[cur] = false;
    //     ans.push_back(cur);
    //     return false;
    // }

    void bfs(queue<char>& qu, unordered_map<char,int>& indegree) {
        while(!qu.empty()) {
            char ch = qu.front();
            qu.pop();
            ans += ch;
            for(char ch_:adj[ch]) {
                if(--indegree[ch_] == 0) {
                    qu.push(ch_);
                }
            }
        }
        if(ans.size() != indegree.size())
            ans = "";
        return;
    }

public:
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1)
            return words[0];
        int n = words.size();
        unordered_map<char,int> indegree;

        for(auto word:words) {
            for(char ch:word) {
                adj[ch] = {};
                indegree[ch] = 0;
            }
        }
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
            indegree[s2[ind2]]++;
        }
        queue<char> qu;
        for(auto itr = indegree.begin();itr != indegree.end();itr++) {
            char ch = itr->first;
            if(indegree[ch] == 0)
                qu.push(ch);
        }
        bfs(qu, indegree);
        return ans;
    }
};
