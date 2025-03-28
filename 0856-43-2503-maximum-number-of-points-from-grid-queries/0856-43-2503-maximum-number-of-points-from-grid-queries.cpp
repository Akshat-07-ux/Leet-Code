class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        vector<int> answer(k, 0);

        // Sorting queries with their original indices
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < k; i++) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-Heap for processing cells in increasing order
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        // Direction vectors for moving up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        
        int points = 0, idx = 0;

        for (auto& [query, queryIdx] : sortedQueries) {
            // Process all cells in the heap that are reachable for this query
            while (!pq.empty() && pq.top().first < query) {
                auto [value, cell] = pq.top();
                pq.pop();
                int x = cell.first, y = cell.second;
                
                points++; // We can visit this cell
                
                // Try all 4 directions
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }
            answer[queryIdx] = points;
        }
        
        return answer;
    }
};