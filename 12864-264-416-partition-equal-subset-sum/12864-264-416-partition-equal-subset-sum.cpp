class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;

        // If total sum is odd, can't split into two equal subsets
        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();

        // Create a DP table of size (target + 1)
        vector<bool> dp(target + 1, false);
        dp[0] = true; // base case: 0 sum is always possible

        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
