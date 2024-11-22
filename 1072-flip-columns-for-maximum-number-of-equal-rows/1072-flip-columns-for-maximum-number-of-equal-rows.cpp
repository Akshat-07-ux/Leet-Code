class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        int maxRows = 0;

        for (auto& row : matrix) {
            string pattern = "";
            string flippedPattern = "";

            // Generate the pattern and flipped pattern for the current row
            for (int cell : row) {
                pattern += (cell == row[0]) ? '1' : '0'; // Pattern for aligning with the first cell
                flippedPattern += (cell == row[0]) ? '0' : '1'; // Flipped pattern
            }

            // Increment the count of this pattern
            patternCount[pattern]++;
            maxRows = max(maxRows, patternCount[pattern]); // Track the maximum rows with the same pattern
        }

        return maxRows;
    }
};
