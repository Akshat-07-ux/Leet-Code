class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAND = 0;
        int longest = 0;
        int currentLength = 0;

        // Find the maximum value in the array
        for (int num : nums) {
            maxAND = max(maxAND, num);
        }

        // Traverse the array to find the longest subarray with bitwise AND equal to maxAND
        for (int num : nums) {
            if (num == maxAND) {
                currentLength++;
                longest = max(longest, currentLength);
            } else {
                currentLength = 0;
            }
        }

        return longest;
    }
};