class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        // Initialize the result vector with size rowIndex + 1
        std::vector<int> row(rowIndex + 1);
        row[0] = 1; // The first element is always 1

        for (int i = 1; i <= rowIndex; ++i) {
            // Set the last element of the row to 1
            row[i] = 1;
            // Update the current row elements from the end to the start
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1]; // Each element is the sum of the two above it
            }
        }

        return row; // Return the constructed row
    }
};