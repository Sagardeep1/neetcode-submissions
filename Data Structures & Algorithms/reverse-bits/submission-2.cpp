class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t factor = pow(2,31);
        uint32_t ans = 0;
        for(int i=0;i<32;i++) {
            ans += factor * (n & 1);
            n = n >> 1;
            factor = factor >> 1;
        }
        return ans;
    }
};