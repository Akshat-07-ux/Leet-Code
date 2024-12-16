class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            // Find the index of the minimum element
            int minIndex = 0;
            for (int j = 1; j < nums.size(); ++j) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            // Update the minimum element
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};