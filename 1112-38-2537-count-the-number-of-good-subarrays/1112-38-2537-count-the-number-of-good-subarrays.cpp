class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        long long count = 0;
        long long pairs = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Add nums[right] to the window and update pairs
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            // While we have enough pairs, count valid subarrays
            while (pairs >= k) {
                count += n - right; // all subarrays from [left...right] to [left...n-1]
                pairs -= freq[nums[left]] - 1; // remove contribution of nums[left]
                freq[nums[left]]--;
                left++;
            }
        }

        return count;
    }
};