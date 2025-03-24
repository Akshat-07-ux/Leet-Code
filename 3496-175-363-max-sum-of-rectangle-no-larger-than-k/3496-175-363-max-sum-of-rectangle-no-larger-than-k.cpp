class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size();
        int maxSum = INT_MIN;

        // Iterate over all row pairs
        for (int top = 0; top < rows; ++top) {
            vector<int> colSum(cols, 0); // Column-wise sum
            
            for (int bottom = top; bottom < rows; ++bottom) {
                // Compute column-wise prefix sum
                for (int c = 0; c < cols; ++c) {
                    colSum[c] += matrix[bottom][c];
                }

                // Find the max subarray sum no larger than k using set (Kadane + Binary Search)
                set<int> prefixSums;
                prefixSums.insert(0);
                int runningSum = 0, best = INT_MIN;

                for (int sum : colSum) {
                    runningSum += sum;

                    // Find smallest prefix sum so that (runningSum - prefix) <= k
                    auto it = prefixSums.lower_bound(runningSum - k);
                    if (it != prefixSums.end()) {
                        best = max(best, runningSum - *it);
                    }

                    // Insert runningSum into prefix set
                    prefixSums.insert(runningSum);
                }

                maxSum = max(maxSum, best);
            }
        }
        
        return maxSum;
    }
};