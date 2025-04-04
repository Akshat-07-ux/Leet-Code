class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int n) {
        int count = 0, row = n - 1, col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += (row + 1);  // All elements in this column up to 'row' are <= mid
                col++;  // Move to the next column
            } else {
                row--;  // Move to the previous row
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countLessEqual(matrix, mid, n);

            if (count < k) {
                left = mid + 1; // Need more elements, increase left bound
            } else {
                right = mid; // Possible kth smallest, narrow the search space
            }
        }
        return left;
    }
};