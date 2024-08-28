class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count = 0;
        
        // Helper function to perform DFS
        auto dfs = [&](int i, int j, auto& dfs_ref) -> bool {
            // If out of bounds or the cell is water in grid2, return true
            if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
                return true;
            }
            
            // Mark the cell as visited by setting it to 0
            grid2[i][j] = 0;
            
            // Initialize isSubIsland as true
            bool isSubIsland = true;
            
            // Check if this cell is part of an island in grid1
            if (grid1[i][j] == 0) {
                isSubIsland = false;
            }
            
            // Explore the four directions
            bool up = dfs_ref(i - 1, j, dfs_ref);
            bool down = dfs_ref(i + 1, j, dfs_ref);
            bool left = dfs_ref(i, j - 1, dfs_ref);
            bool right = dfs_ref(i, j + 1, dfs_ref);
            
            // The current part is a sub-island only if all parts are sub-islands
            return isSubIsland && up && down && left && right;
        };
        
        // Iterate through all cells in grid2
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find a part of an island in grid2, start DFS
                if (grid2[i][j] == 1) {
                    if (dfs(i, j, dfs)) {
                        ++count;
                    }
                }
            }
        }
        
        return count;
    }
};