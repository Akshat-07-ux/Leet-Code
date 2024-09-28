class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Create a 2D DP array where dp[i][j] will store the number of distinct subsequences
        // of s[0...i-1] that match t[0...j-1]
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Every string s has exactly one subsequence that matches an empty string t, which is ""
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
        // Fill the dp array
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    // We can either include this character or exclude it
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // We can only exclude this character
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        // The answer will be in dp[m][n]
        return dp[m][n];
    }
};