class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if the total number of elements matches the required size for the 2D array
        if (m * n != original.size()) {
            return {}; // Return an empty 2D array if the size doesn't match
        }
        
        vector<vector<int>> result(m, vector<int>(n)); // Initialize the 2D array with m rows and n columns
        
        for (int i = 0; i < original.size(); ++i) {
            // Calculate the row and column index in the 2D array
            int row = i / n;
            int col = i % n;
            result[row][col] = original[i]; // Assign the value from the original array to the 2D array
        }
        
        return result;
    }
};