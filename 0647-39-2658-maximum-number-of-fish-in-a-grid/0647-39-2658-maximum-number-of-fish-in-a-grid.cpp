class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        // Helper function for DFS
        auto dfs = [&](int r, int c, auto& dfs) -> int {
            // Check boundaries and if the cell is land or already visited
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
                return 0;
            }

            // Capture the fish at the current cell and mark it as visited
            int fish = grid[r][c];
            grid[r][c] = 0;

            // Explore all adjacent cells
            fish += dfs(r + 1, c, dfs); // Down
            fish += dfs(r - 1, c, dfs); // Up
            fish += dfs(r, c + 1, dfs); // Right
            fish += dfs(r, c - 1, dfs); // Left

            return fish;
        };

        // Iterate through all cells to find the optimal starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) { // Start DFS from water cells only
                    maxFish = max(maxFish, dfs(i, j, dfs));
                }
            }
        }

        return maxFish;
    }
};