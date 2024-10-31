class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int n = robot.size();
        int m = factory.size();
        
        // DP array: first index is number of robots processed
        // second index is number of factories used
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX / 2));
        
        // Base case: 0 robots processed
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        
        // Process each robot
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Try repairing robots at current factory
                long long total_dist = 0;
                for (int k = 0; k < min(i, factory[j-1][1]); k++) {
                    // Calculate distance for this robot
                    total_dist += abs(robot[i-k-1] - factory[j-1][0]);
                    
                    // Update minimum distance
                    dp[i][j] = min(dp[i][j], 
                        dp[i-k-1][j-1] + total_dist);
                }
                
                // Option to not use this factory - take previous best
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        }
        
        // Return minimum total distance for all robots
        return dp[n][m];
    }
};
