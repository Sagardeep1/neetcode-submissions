class TrieNode {
public:
    vector<TrieNode*> children;
    bool end_flag;

    TrieNode() {
        children.resize(26,nullptr);
        end_flag = false;
    }
};

class Solution {
    unordered_set<string> ans;

    bool isValid(vector<vector<char>>& board, int r, int c) {
        if(r>=0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] != '*')
            return true;
        return false;
    }
    
    void dfs_search(vector<vector<char>>& board, int r, int c, TrieNode* root, 
     string str) {
        if(!root)
            return;
        if(root->end_flag) {
            ans.insert(str);
        }
        if(!isValid(board,r,c))
            return;
        if(root->children[board[r][c]-'a']) {
            str.push_back(board[r][c]);
            char ch = board[r][c];
            board[r][c] = '*';
            dfs_search(board,r+1,c,root->children[ch-'a'],str);
            dfs_search(board,r,c+1,root->children[ch-'a'],str);
            dfs_search(board,r-1,c,root->children[ch-'a'],str);
            dfs_search(board,r,c-1,root->children[ch-'a'],str);
            board[r][c] = ch;
            str.pop_back();
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string str:words) {
            TrieNode* node = root;
            for(char ch:str) {
                if(!node->children[ch-'a'])
                    node->children[ch-'a'] = new TrieNode();
                node = node->children[ch-'a'];
            }
            node->end_flag = true;
        }
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!root->children[board[i][j]-'a'])
                    continue;
                dfs_search(board,i,j,root,"");
            }
        }
        vector<string> res(ans.begin(),ans.end());
        return res;
    }
};
