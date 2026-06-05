class Solution {

    bool isvalid(vector<vector<char>>& board, vector<vector<bool>>& vis, 
     int r, int c) {
        if(r < board.size() && c < board[0].size() && !vis[r][c])
            return true;
        return false;    
    }

    bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& 
    vis, int r, int c, string res) {
        if(res.size() == word.size()) {
            if(res == word)
                return true;
            return false;
        }
        if(!isvalid(board,vis,r,c)) return false;
        res.push_back(board[r][c]);
        vis[r][c] = true;
        if(backtrack(board,word,vis,r-1,c,res) 
         || backtrack(board,word,vis,r,c+1,res)
         || backtrack(board,word,vis,r+1,c,res) 
         || backtrack(board,word,vis,r,c-1,res))
            return true;
        res.pop_back();
        vis[r][c] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] != word[0])
                    continue;
                if(backtrack(board,word,vis,i,j,""))
                    return true;
            }
        }
        return false;
    }
};
