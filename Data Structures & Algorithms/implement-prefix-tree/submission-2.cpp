class TrieNode {
public:
    unordered_map<char,TrieNode*> mp;
    bool end_flag = false;
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch:word) {
            if(node->mp.find(ch) == node->mp.end())
                node->mp[ch] = new TrieNode();
            node = node->mp[ch];
        }
        node->end_flag = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch:word) {
            if(node->mp.find(ch) == node->mp.end())
                return false;
            node = node->mp[ch];
        }
        if(node->end_flag)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch:prefix) {
            if(node->mp.find(ch) == node->mp.end())
                return false;
            node = node->mp[ch];
        }
        return true;
    }
};
