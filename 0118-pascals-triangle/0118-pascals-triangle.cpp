class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;

        // Create the Pascal's triangle row by row
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // Initialize each row with 1s

            // Fill in the values between the 1s
            for (int j = 1; j < i; j++) {
                row[j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
            }

            // Add the row to the triangle
            pascalTriangle.push_back(row);
        }

        return pascalTriangle;
    }
};
