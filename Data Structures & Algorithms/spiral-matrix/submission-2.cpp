class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int ref = min(m,n);
        for(int i=0 ; i <= (ref-1)/2 ; i++) {
            int j, k;
            for(j=i ; j < n-i ; j++)
                ans.push_back(matrix[i][j]);
            for(k = i+1 ; k < m-i ; k++) 
                ans.push_back(matrix[k][n-1-i]);
            if(i == m-1-i) break;
            for(j = n-2-i ; j >= i ; j--)
                ans.push_back(matrix[m-1-i][j]);
            if(n-1-i == i) break;
            for(k = m-2-i ; k > i ; k--)
                ans.push_back(matrix[k][i]);
        }
        return ans;
    }
};
