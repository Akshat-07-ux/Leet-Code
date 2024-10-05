class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        
        // Traverse through the prices array
        for (int i = 1; i < prices.size(); i++) {
            // If prices[i] is greater than prices[i-1], add the difference to profit
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }
        
        return totalProfit;
    }
};