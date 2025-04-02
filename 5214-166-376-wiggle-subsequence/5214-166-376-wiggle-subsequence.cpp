class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n; // If there's only one element, the length is 1

        int up = 1, down = 1; // At least one element is always counted

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1; // Increase after decrease
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1; // Decrease after increase
            }
        }

        return max(up, down);
    }
};