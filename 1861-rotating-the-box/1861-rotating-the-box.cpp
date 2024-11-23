class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // Step 1: Simulate gravity for each row
        for (int i = 0; i < m; ++i) {
            int emptyIndex = n - 1; // Start from the rightmost cell
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    // Obstacle: Update emptyIndex to just before this obstacle
                    emptyIndex = j - 1;
                } else if (box[i][j] == '#') {
                    // Stone: Move it to the furthest empty cell
                    swap(box[i][j], box[i][emptyIndex]);
                    --emptyIndex;
                }
            }
        }

        // Step 2: Rotate the box 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }

        return rotatedBox;
    }
};