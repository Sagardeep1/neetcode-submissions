class TrieNode {
public:
    vector<TrieNode*> children;
    bool end_flag;

    TrieNode() {
        children.resize(26,nullptr);
        end_flag = false;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs_search(TrieNode* node, string word, int ind) {
        if(ind == word.size()) {
            if(node->end_flag)
                return true;
            return false;
        }

        if(word[ind] == '.') {
            for(int i=0;i<26;i++) {
                if(!node->children[i])
                    continue;
                if(dfs_search(node->children[i],word,ind+1))
                    return true;
            }
            return false;
        }
        else {
            if(!node->children[word[ind]-'a'])
                return false;
            return dfs_search(node->children[word[ind]-'a'],word,ind+1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch:word) {
            if(!node->children[ch-'a'])
                node->children[ch-'a'] = new TrieNode();
            node = node->children[ch-'a'];
        }
        node->end_flag = true;
    }
    
    bool search(string word) {
        return dfs_search(root,word,0);
    }
};
