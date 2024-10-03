class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Calculate total sum of the array
        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Find the remainder when the total sum is divided by p
        int targetRemainder = totalSum % p;
        if (targetRemainder == 0) {
            // If the total sum is already divisible by p, no subarray needs to be removed
            return 0;
        }

        // Hash map to store the prefix sum remainder and the index
        unordered_map<int, int> prefixSumMod;
        prefixSumMod[0] = -1;  // To handle cases where the entire prefix matches the target

        int minLength = nums.size();
        long currentPrefixSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // Update the current prefix sum
            currentPrefixSum += nums[i];

            // Find the remainder of the current prefix sum with respect to p
            int currentMod = currentPrefixSum % p;

            // Calculate the desired remainder to remove
            int desiredMod = (currentMod - targetRemainder + p) % p;

            // Check if we've seen this remainder before
            if (prefixSumMod.find(desiredMod) != prefixSumMod.end()) {
                // If yes, calculate the length of the subarray we can remove
                minLength = min(minLength, i - prefixSumMod[desiredMod]);
            }

            // Store the current prefix sum remainder with the index
            prefixSumMod[currentMod] = i;
        }

        // If we couldn't find any valid subarray to remove
        return (minLength == nums.size()) ? -1 : minLength;
    }
};