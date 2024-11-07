class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid; // Minimum must be in the left half
            } else if (nums[mid] > nums[right]) {
                left = mid + 1; // Minimum must be in the right half
            } else {
                // nums[mid] == nums[right], discard the rightmost duplicate
                right--;
            }
        }
        
        return nums[left];
    }
};