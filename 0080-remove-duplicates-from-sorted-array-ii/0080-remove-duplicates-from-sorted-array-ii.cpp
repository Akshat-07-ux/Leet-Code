class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // If the array length is 2 or less, no need to process

        int index = 2; // Start from the third element

        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                ++index;
            }
        }

        return index;
    }
};