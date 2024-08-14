class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            int left = 0;
            
            for (int right = 0; right < n; ++right) {
                while (nums[right] - nums[left] > mid) {
                    ++left;
                }
                count += right - left;
            }
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};