class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, ans = 0, mask = 0xFFFFFFFF;     // 2^32 - 1

        for(int i=0;i<32;i++) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_cur = bit_a ^ bit_b ^ carry;
            carry = (bit_a + bit_b + carry) >= 2;
            if(bit_cur)
                ans |= (1 << i);
        }
        // if(ans > 0x7FFFFFFF)
        //     ans = ~(ans ^ mask);
        return ans;
    }
};
