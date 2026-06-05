class Solution {

    bool isvalid(vector<vector<char>>& board, string word, int r, int c, int ind) {
        if(r < board.size() && c < board[0].size() && board[r][c] != '*'
         && board[r][c] == word[ind])
            return true;
        return false;    
    }

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, 
     string res, int ind) {
        if(res.size() == word.size()) {
            if(res == word)
                return true;
            return false;
        }
        if(!isvalid(board,word,r,c,ind))
            return false;
        char ch_orig = board[r][c];
        res.push_back(ch_orig);
        board[r][c] = '*';
        if(backtrack(board,word,r-1,c,res,ind+1) 
         || backtrack(board,word,r,c+1,res,ind+1)
         || backtrack(board,word,r+1,c,res,ind+1) 
         || backtrack(board,word,r,c-1,res,ind+1))
            return true;
        res.pop_back();
        board[r][c] = ch_orig;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        //vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] != word[0])
                    continue;
                if(backtrack(board,word,i,j,"",0))
                    return true;
            }
        }
        return false;
    }
};
