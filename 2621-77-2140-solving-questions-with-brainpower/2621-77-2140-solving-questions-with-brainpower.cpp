class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // DP array to store max points from index i to end
        
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int skip = questions[i][1];
            
            // Solve this question
            long long solve = points;
            if (i + skip + 1 < n) {
                solve += dp[i + skip + 1]; // Add future possible max points
            }
            
            // Skip this question
            long long skip_q = dp[i + 1];
            
            // Store the best choice
            dp[i] = max(solve, skip_q);
        }
        
        return dp[0]; // Maximum points starting from index 0
    }
};