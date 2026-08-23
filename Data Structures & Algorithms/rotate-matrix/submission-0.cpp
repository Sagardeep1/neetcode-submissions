class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i< n/2 ; i++) {
            for(int j = i ; j < n-i-1 ; j++) {
                int bk1, bk2;
                bk1 = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                bk2 = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = bk1;
                bk1 = bk2;
                bk2 = matrix[n-1-j][i];
                matrix[n-1-j][i] = bk1;
                matrix[i][j] = bk2;
            }
        }
    }
};
