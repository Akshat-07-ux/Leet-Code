class Solution {
public:
    int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // If grid is smaller than 3x3, return 0 immediately
        if (rows < 3 || cols < 3) return 0;

        // Function to check if a 3x3 grid is a magic square
        auto isMagic = [&](int r, int c) {
            // Check if all numbers from 1 to 9 are present
            std::vector<int> nums(10, 0);
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int val = grid[r + i][c + j];
                    if (val < 1 || val > 9 || nums[val]) return false;
                    nums[val] = 1;
                }
            }
            
            // Check sums
            int sum1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
            int sum2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
            int sum3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];
            int sum4 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
            int sum5 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
            int sum6 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];
            int sum7 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
            int sum8 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
            
            return (sum1 == 15 && sum2 == 15 && sum3 == 15 &&
                    sum4 == 15 && sum5 == 15 && sum6 == 15 &&
                    sum7 == 15 && sum8 == 15);
        };

        // Iterate over each 3x3 grid
        for (int r = 0; r <= rows - 3; ++r) {
            for (int c = 0; c <= cols - 3; ++c) {
                if (isMagic(r, c)) {
                    ++count;
                }
            }
        }

        return count;
    }
};
