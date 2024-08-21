class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;  // Single character needs one print
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    int minTurns = INT_MAX;
                    for (int k = i; k < j; ++k) {
                        minTurns = min(minTurns, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = minTurns;
                }
            }
        }
        
        return dp[0][n - 1];
    }
};