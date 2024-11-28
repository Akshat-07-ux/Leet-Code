class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Deque for 0-1 BFS
        deque<pair<int, int>> dq;
        
        // Distance vector to store minimum obstacles to reach each cell
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Start from the top-left corner
        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;

                        // Push to front if no obstacle, back if obstacle
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        // Return the minimum obstacles to reach bottom-right corner
        return dist[m - 1][n - 1];
    }
};