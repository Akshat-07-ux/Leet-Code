class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // To track the frequency of elements
        long long maxSum = 0, currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Include the current element in the window
            freq[nums[right]]++;
            currentSum += nums[right];

            // If the window size exceeds `k`, shrink it from the left
            while (right - left + 1 > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                currentSum -= nums[left];
                left++;
            }

            // Check if the current window has all distinct elements and size `k`
            if (right - left + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};