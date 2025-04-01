class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Build the DP table
        for (int len = 2; len <= n; len++) { // Length of range
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = INT_MAX;
                for (int k = l; k <= r; k++) {
                    int cost = k + max((k > l ? dp[l][k - 1] : 0), (k < r ? dp[k + 1][r] : 0));
                    dp[l][r] = min(dp[l][r], cost);
                }
            }
        }

        return dp[1][n];
    }
};