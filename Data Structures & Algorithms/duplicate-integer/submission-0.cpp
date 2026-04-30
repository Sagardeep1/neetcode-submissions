class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> se;
        for(auto num:nums) {
            if(se.find(num) != se.end())
                return true;
            se.insert(num);
        }
        return false;
    }
};