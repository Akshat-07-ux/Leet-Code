class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        
        // Mark the current cell as visited (change 'O' to '#')
        board[i][j] = '#';
        
        // Explore the four directions (up, down, left, right)
        dfs(i - 1, j, board, m, n); // up
        dfs(i + 1, j, board, m, n); // down
        dfs(i, j - 1, board, m, n); // left
        dfs(i, j + 1, board, m, n); // right
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // Step 1: Mark all 'O's connected to the boundary with '#'
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, board, m, n); // Left boundary
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board, m, n); // Right boundary
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j, board, m, n); // Top boundary
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board, m, n); // Bottom boundary
        }
        
        // Step 2: Convert all remaining 'O's to 'X' and restore '#' to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded 'O' to 'X'
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O'; // Restore boundary connected 'O'
                }
            }
        }
    }
};