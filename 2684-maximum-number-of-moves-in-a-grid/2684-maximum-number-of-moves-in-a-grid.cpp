class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize dp with -1 as we need to store maximum moves from each cell
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int result = 0;

        // Function to perform DFS with memoization
        function<int(int, int)> dfs = [&](int i, int j) {
            if (j == n - 1) return 0; // last column reached, no more moves possible
            
            if (dp[i][j] != -1) return dp[i][j]; // if already computed

            int max_moves = 0;
            // Check all three possible directions
            if (i > 0 && grid[i - 1][j + 1] > grid[i][j])
                max_moves = max(max_moves, 1 + dfs(i - 1, j + 1));
            if (grid[i][j + 1] > grid[i][j])
                max_moves = max(max_moves, 1 + dfs(i, j + 1));
            if (i < m - 1 && grid[i + 1][j + 1] > grid[i][j])
                max_moves = max(max_moves, 1 + dfs(i + 1, j + 1));

            return dp[i][j] = max_moves;
        };

        // Start DFS from each cell in the first column
        for (int i = 0; i < m; ++i) {
            result = max(result, dfs(i, 0));
        }

        return result;
    }
};