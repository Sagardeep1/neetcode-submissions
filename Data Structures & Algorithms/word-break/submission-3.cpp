class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    bool is_word = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char ch: word) {
            if(!node->children.contains(ch))
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->is_word = true;
    }

    bool search(string& s, int i, int j) {
        TrieNode* node = root;
        for(int ind = i; ind <= j; ind++) {
            if(!node->children.contains(s[ind]))
                return false;
            node = node->children[s[ind]];
        }
        return node->is_word;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        int maxLen = 0;
        for(string& word : wordDict) {
            trie.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }

        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int i=n-1;i>=0;i--) {
            for(int j=i;j < min(n, i+maxLen);j++) {
                if(trie.search(s,i,j)) {
                    dp[i] = dp[j+1];
                    if(dp[i]) break;
                }
            }
        }
        return dp[0];
    }
};
