class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Edge case: If we can't even move from (0, 0) to (0, 1) or (1, 0)
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0); // (time, row, col)

        while (!pq.empty()) {
            auto [currentTime, row, col] = pq.top();
            pq.pop();

            if (row == m - 1 && col == n - 1) {
                return currentTime;
            }

            if (currentTime >= visited[row][col]) continue;
            visited[row][col] = currentTime;

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) continue;

                int waitTime = max(0, grid[newRow][newCol] - (currentTime + 1));
                if (waitTime % 2 == 1) waitTime++; // Ensure even parity for alternate routes
                int newTime = currentTime + 1 + waitTime;

                if (newTime < visited[newRow][newCol]) {
                    pq.emplace(newTime, newRow, newCol);
                }
            }
        }

        return -1;
    }
};