class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer(n);
        
        for (int i = 0; i < n; ++i) {
            answer[i] = prices[i]; // Initialize with the original price
            for (int j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) {
                    answer[i] -= prices[j]; // Apply discount
                    break;
                }
            }
        }
        
        return answer;
    }
};