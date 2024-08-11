class Solution {

private:
    int m, n;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y]) {
            return;
        }
        
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(grid, nx, ny, visited);
        }
    }
    
    bool isConnected(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    islands++;
                    if (islands > 1) return false;
                }
            }
        }
        
        return islands == 1;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // Check if the grid is already disconnected
        if (!isConnected(grid)) return 0;
        
        // Check if removing any single cell disconnects the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (!isConnected(grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        // If we can't disconnect with a single removal, we need 2 days
        return 2;
    }
};