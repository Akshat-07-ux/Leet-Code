class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // Create a DP table initialized with a large value
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        // Base case: minimum health needed at the princess's cell
        dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);

        // Fill the DP table from bottom-right to top-left
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i < m - 1) { // Downward move
                    dp[i][j] = min(dp[i][j], max(1, dp[i+1][j] - dungeon[i][j]));
                }
                if (j < n - 1) { // Rightward move
                    dp[i][j] = min(dp[i][j], max(1, dp[i][j+1] - dungeon[i][j]));
                }
            }
        }

        // The top-left cell contains the minimum initial health
        return dp[0][0];
    }
};