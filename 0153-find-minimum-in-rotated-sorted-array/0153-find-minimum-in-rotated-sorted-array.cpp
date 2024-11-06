class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If the middle element is greater than the rightmost element,
            // then the minimum is in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // If the middle element is less than or equal to the rightmost element,
            // the minimum is in the left half, including mid
            else {
                right = mid;
            }
        }

        // When left == right, we've found the minimum element
        return nums[left];
    }
};