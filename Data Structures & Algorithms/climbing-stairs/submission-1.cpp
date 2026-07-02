class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5)/2.0;
        double psi = (1 - sqrt5)/2.0;
        n++;
        int ans = round((pow(phi,n) - pow(psi,n)) / sqrt5);
        return ans;
    }
};