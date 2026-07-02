class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int n_2 = 1, n_1 = 1;
        int ans;
        for(int i=2;i<=n;i++) {
            ans = n_2 + n_1;
            n_2 = n_1;
            n_1 = ans;
        }
        return ans;
    }
};
