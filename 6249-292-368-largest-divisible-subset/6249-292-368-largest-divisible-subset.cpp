class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());

        // Step 2: Initialize DP arrays
        std::vector<int> dp(n, 1); // dp[i] will store the size of the largest divisible subset ending with nums[i]
        std::vector<int> prev(n, -1); // prev[i] will store the index of the previous element in the subset
        int maxIndex = 0; // Index of the largest element in the maximum subset

        // Step 3: Populate the DP arrays
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        // Step 4: Reconstruct the largest divisible subset
        std::vector<int> largestSubset;
        for (int k = maxIndex; k >= 0; k = prev[k]) {
            largestSubset.push_back(nums[k]);
            if (prev[k] == -1) break;
        }

        return largestSubset;
    }
};