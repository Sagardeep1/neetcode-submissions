class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //if(prices.empty()) return 0;
        int profit = 0;
        int buyPrice = 105;

        for(int price : prices) {
            profit = max(profit, price - buyPrice);
            buyPrice = min(price, buyPrice);
        }
        return profit;
    }
};
