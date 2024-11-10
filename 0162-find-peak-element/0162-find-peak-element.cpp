class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Check if the mid element is greater than its next element
            if (nums[mid] > nums[mid + 1]) {
                // Peak must be on the left side (including mid)
                right = mid;
            } else {
                // Peak must be on the right side
                left = mid + 1;
            }
        }
        
        // When left == right, we have found a peak element
        return left;
    }
};