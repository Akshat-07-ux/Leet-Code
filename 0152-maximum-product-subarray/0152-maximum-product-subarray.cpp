class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int maxProd = nums[0]; // Maximum product ending at the current position
        int minProd = nums[0]; // Minimum product ending at the current position
        int result = nums[0];  // Result stores the maximum product found so far

        // Traverse from the second element to the end of the array
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                std::swap(maxProd, minProd); // Swap when encountering a negative element
            }

            // Update maxProd and minProd
            maxProd = std::max(nums[i], maxProd * nums[i]);
            minProd = std::min(nums[i], minProd * nums[i]);

            // Update the result with the maximum product so far
            result = std::max(result, maxProd);
        }

        return result;
    }
};