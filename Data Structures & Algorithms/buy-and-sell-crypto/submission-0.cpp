class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //if(prices.empty()) return 0;

        int ans = 0;
        int lo = prices[0];
        for(int i=1;i<prices.size();i++) {
            ans = max(ans,prices[i]-lo);
            lo = min(lo,prices[i]);
        }
        return ans;
    }
};
