class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Update the minimum price if the current price is lower
            minPrice = min(minPrice, price);
            // Calculate profit if we sell at the current price and update max profit
            int profit = price - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};