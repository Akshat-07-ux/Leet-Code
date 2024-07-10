class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num == '.') continue;
                
                // Check row
                if (rows[i].find(num) != rows[i].end()) {
                    return false;
                }
                rows[i].insert(num);
                
                // Check column
                if (cols[j].find(num) != cols[j].end()) {
                    return false;
                }
                cols[j].insert(num);
                
                // Check 3x3 box
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].find(num) != boxes[boxIndex].end()) {
                    return false;
                }
                boxes[boxIndex].insert(num);
            }
        }
        
        return true;
    }
};