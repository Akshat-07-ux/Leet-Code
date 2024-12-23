class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX; // Initialize the minimum length to the largest possible value.
        int currentSum = 0; // To keep track of the current window sum.
        int left = 0; // Left pointer of the sliding window.

        // Iterate over the array with the right pointer.
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right]; // Add the current element to the window sum.

            // Shrink the window from the left as long as the current sum is >= target.
            while (currentSum >= target) {
                minLength = min(minLength, right - left + 1); // Update the minimum length.
                currentSum -= nums[left]; // Remove the leftmost element from the window.
                ++left; // Move the left pointer to the right.
            }
        }

        // If minLength is not updated, return 0. Otherwise, return minLength.
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};