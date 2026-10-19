class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_exp = 0, xor_ob = 0;
        for(int i=1 ; i <= n ;i++)
            xor_exp ^= i;
        for(int& num : nums)
            xor_ob ^= num;
        return (xor_exp ^ xor_ob);
    }
};
