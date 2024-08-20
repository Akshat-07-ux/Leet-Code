class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> suffixSum(n + 1, 0);

        // Calculate the suffix sum for the piles array
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // dp[i][m] represents the maximum stones Alice can get starting from index i with M = m
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                    dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                }
            }
        }

        return dp[0][1];
    }
};