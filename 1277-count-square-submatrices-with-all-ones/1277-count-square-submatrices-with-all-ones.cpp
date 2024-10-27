class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int totalSquares = 0;
        
        // Initialize the DP table with the same values as the input matrix
        vector<vector<int>> dp = matrix;
        
        // Iterate over each cell starting from (1,1)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    // Update dp[i][j] with the minimum of the neighboring cells + 1
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
            }
        }
        
        // Sum all values in dp to get the total number of squares
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSquares += dp[i][j];
            }
        }
        
        return totalSquares;
    }
};