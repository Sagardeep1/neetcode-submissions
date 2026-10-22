class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> count(n+1,0);
        int offset = 1;
        for(int i = 1 ; i <= n ;i++) {
            if(i == offset * 2) {
                offset = i;
            }
            count[i] = 1 + count[i - offset];
        }
        return count;
    }
};
