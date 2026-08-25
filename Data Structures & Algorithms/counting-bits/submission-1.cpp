class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> count(n+1,0);
        int ref = 0, offset = 0;
        for(int i = 1 ; i <= n ;i++) {
            if(i == pow(2,ref)) {
                ref++;
                offset = 0;
            }
            count[i] = 1 + count[offset];
            offset++;
        }
        return count;
    }
};
