class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbsoluteValue = INT_MAX;

        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = matrix[i][j];
                totalSum += abs(value);
                if (value < 0) {
                    negativeCount++;
                }
                minAbsoluteValue = min(minAbsoluteValue, abs(value));
            }
        }

        // If there are an odd number of negative elements, subtract twice the smallest absolute value
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsoluteValue;
        }

        return totalSum;
    }
};