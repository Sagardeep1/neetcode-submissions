class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans = 0;
        int ref = min(m-1,n-1), tot = m+n-2;
        for(int i=1 ; i<= ref ; i++) {
            ans += log(tot-ref+i) - log(i);
        }
        return (int)round(exp(ans));
    }
};
