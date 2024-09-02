class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Pointer for the end of the meaningful part of nums1
        int j = n - 1;  // Pointer for the end of nums2
        int k = m + n - 1;  // Pointer for the end of nums1

        // Start from the end of both arrays and work backwards
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

        // No need to copy the remaining elements of nums1, because they are already in place
    }
};