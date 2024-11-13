class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            // Use binary search to find the range of j indices for each i
            int left = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;

            if (left <= right) {
                count += (right - left + 1);
            }
        }
        
        return count;
    }
};