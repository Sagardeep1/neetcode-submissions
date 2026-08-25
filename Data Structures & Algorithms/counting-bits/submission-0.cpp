class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> count(n+1,0);
        int ref = 2;
        for(int i = 1 ; i <= n ;i++) {
            if(i == ref) ref *= 2;
            count[i] = 1 + count[i ^ (ref/2)];
        }
        return count;
    }
};
