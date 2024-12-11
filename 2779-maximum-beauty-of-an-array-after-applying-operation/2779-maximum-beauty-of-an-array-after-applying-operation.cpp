class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Sort the array to group potential equal elements together
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxBeauty = 0;
        int left = 0;

        // Use a sliding window to find the maximum subsequence length
        for (int right = 0; right < n; ++right) {
            // Check if the current window satisfies the condition
            while (nums[right] - nums[left] > 2 * k) {
                ++left; // Shrink the window from the left
            }
            // Update the maximum beauty
            maxBeauty = max(maxBeauty, right - left + 1);
        }

        return maxBeauty;
    }
};
