class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Apply the given operations
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1] && nums[i] != 0) {
                nums[i] *= 2;   // Multiply nums[i] by 2
                nums[i + 1] = 0; // Set nums[i+1] to 0
            }
        }

        // Step 2: Shift all zeros to the end
        int insertPos = 0; // Position to place the next non-zero element

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[insertPos]); // Swap non-zero elements to the front
                insertPos++;
            }
        }

        return nums;
    }
};