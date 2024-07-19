class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        
        for (int i = 0; i < m; i++) {
            int minInRow = matrix[i][0];
            int minColIndex = 0;
            
            // Find the minimum in the row
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < minInRow) {
                    minInRow = matrix[i][j];
                    minColIndex = j;
                }
            }
            
            // Check if it's maximum in its column
            bool isMaxInCol = true;
            for (int k = 0; k < m; k++) {
                if (matrix[k][minColIndex] > minInRow) {
                    isMaxInCol = false;
                    break;
                }
            }
            
            if (isMaxInCol) {
                result.push_back(minInRow);
            }
        }
        
        return result;
    }
};