class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxVal = (1 << maximumBit) - 1;  // Maximum value with maximumBit bits
        vector<int> result(n);
        
        // Compute the XOR of the entire array
        int currentXor = 0;
        for (int num : nums) {
            currentXor ^= num;
        }

        // Iterate from the end to the beginning
        for (int i = 0; i < n; ++i) {
            // Compute the optimal k for the current prefix XOR
            result[i] = currentXor ^ maxVal;
            // Update the currentXor by removing the last element
            currentXor ^= nums[n - 1 - i];
        }

        return result;
    }
};