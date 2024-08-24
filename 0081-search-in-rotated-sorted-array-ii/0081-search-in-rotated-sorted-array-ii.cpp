class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid is the target
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle the case where we cannot determine the sorted half due to duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // If the left half is sorted
            else if (nums[left] <= nums[mid]) {
                // Target is in the left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else { // Otherwise, search in the right half
                    left = mid + 1;
                }
            }
            // If the right half is sorted
            else {
                // Target is in the right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else { // Otherwise, search in the left half
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
};