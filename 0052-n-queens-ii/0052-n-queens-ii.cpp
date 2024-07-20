class Solution {
public:
    int totalNQueens(int n) {
        vector<int> queens(n, -1); // to store positions of queens in each row
        vector<bool> columns(n, false); // to check if a column is occupied
        vector<bool> diag1(2 * n - 1, false); // to check if a major diagonal is occupied
        vector<bool> diag2(2 * n - 1, false); // to check if a minor diagonal is occupied
        return solveNQueens(n, 0, queens, columns, diag1, diag2);
    }
    
private:
    int solveNQueens(int n, int row, vector<int>& queens, vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            return 1;
        }
        
        int count = 0;
        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            if (columns[col] || diag1[d1] || diag2[d2]) {
                continue;
            }
            
            queens[row] = col;
            columns[col] = diag1[d1] = diag2[d2] = true;
            count += solveNQueens(n, row + 1, queens, columns, diag1, diag2);
            queens[row] = -1;
            columns[col] = diag1[d1] = diag2[d2] = false;
        }
        
        return count;
    }
};