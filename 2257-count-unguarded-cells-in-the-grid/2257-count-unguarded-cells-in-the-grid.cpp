class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark guards (-1) and walls (-2) on the grid
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = -1; // Guard
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = -2; // Wall
        }

        // Directions for moving north, east, south, west
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Mark guarded cells
        for (const auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (const auto& dir : directions) {
                int dx = dir.first, dy = dir.second;
                int nx = x + dx, ny = y + dy;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] < 0) break; // Stop at guard or wall
                    grid[nx][ny] = 1; // Mark cell as guarded
                    nx += dx;
                    ny += dy;
                }
            }
        }

        // Count unoccupied and unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) unguarded++;
            }
        }
        
        return unguarded;
    }
};