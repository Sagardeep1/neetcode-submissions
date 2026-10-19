class Solution {
public:
    int hammingWeight(uint32_t n) {
        int n_bits = 0;
        while(n) {
            if(n & 1)
                n_bits++;
            n = n >> 1;
        }
        return n_bits;
    }
};
