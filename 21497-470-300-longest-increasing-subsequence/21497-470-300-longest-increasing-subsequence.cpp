class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // Create a DP array where dp[i] will store the length of the longest increasing subsequence ending at index i
        vector<int> dp(n, 1); 
        
        // Loop through the array to fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // The result is the maximum value in dp array, which represents the length of the LIS
        return *max_element(dp.begin(), dp.end());
    }
};