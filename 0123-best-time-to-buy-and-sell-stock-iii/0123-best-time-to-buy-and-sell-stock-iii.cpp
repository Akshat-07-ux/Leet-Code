class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        
        // Arrays to store the maximum profit at each point
        vector<int> profit1(n, 0);
        vector<int> profit2(n, 0);
        
        // First pass: Calculate maximum profit for first transaction
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            profit1[i] = max(profit1[i - 1], prices[i] - minPrice);
        }
        
        // Second pass: Calculate maximum profit for second transaction
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            profit2[i] = max(profit2[i + 1], maxPrice - prices[i]);
        }
        
        // Combine the profits from both transactions
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, profit1[i] + profit2[i]);
        }

        return maxProfit;
    }
};