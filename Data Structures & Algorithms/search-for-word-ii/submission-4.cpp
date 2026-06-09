class TrieNode {
public:
    vector<TrieNode*> children;
    int idx;
    int refs;

    TrieNode() {
        children.resize(26,nullptr);
        idx = -1;
        refs = 0;
    }

    void addword(const string& word, int i) {
        TrieNode* node = this;
        for(char ch:word) {
            if(!node->children[ch-'a'])
                node->children[ch-'a'] = new TrieNode();
            node = node->children[ch-'a'];
            node->refs++;
        }
        node->idx = i;
    }
};

class Solution {
    vector<string> res;

    bool isValid(int r, int c, vector<vector<char>>& board, TrieNode* root) {
        if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && 
         board[r][c] != '*' && root->children[board[r][c]-'a'])
            return true;
        return false;
    }

    void dfs_search(TrieNode* root, vector<vector<char>>& board, int r, int c, 
     vector<string>& words) {
        if(!isValid(r,c,board,root))
            return;
        char ch = board[r][c];
        board[r][c] = '*';
        TrieNode* prev = root;
        root = root->children[ch-'a'];
        if(root->idx != -1) {
            res.push_back(words[root->idx]);
            root->idx = -1;
            root->refs--;
            if(root->refs == 0) {
                prev->children[ch-'a'] = nullptr;
                root = nullptr;
                board[r][c] = ch;
                return;
            }
        }
        dfs_search(root,board,r+1,c,words);
        dfs_search(root,board,r-1,c,words);
        dfs_search(root,board,r,c+1,words);
        dfs_search(root,board,r,c-1,words);
        
        board[r][c] = ch;
        return;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i=0;i<words.size();i++)
            root->addword(words[i],i);
        for(int r=0;r<board.size();r++) {
            for(int c = 0;c<board[0].size();c++) {
                dfs_search(root,board,r,c,words);
            }
        }
        return res;
    }
};
