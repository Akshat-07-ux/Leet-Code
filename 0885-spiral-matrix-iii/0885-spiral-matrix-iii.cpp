class Solution {
public:
    std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        std::vector<std::vector<int>> result;
        int total_cells = rows * cols;
        int direction = 0;  // 0=right, 1=down, 2=left, 3=up
        int steps = 1;
        int r = rStart, c = cStart;
        
        result.push_back({r, c});
        
        while (result.size() < total_cells) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < steps; ++j) {
                    if (direction == 0) c++;
                    else if (direction == 1) r++;
                    else if (direction == 2) c--;
                    else if (direction == 3) r--;
                    
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                direction = (direction + 1) % 4;
            }
            steps++;
        }
        
        return result;
    }
};