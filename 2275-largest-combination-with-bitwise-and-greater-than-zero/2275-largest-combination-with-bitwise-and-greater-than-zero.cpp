class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCombinationSize = 0;
        
        // Iterate through each bit position from 0 to 23 (since max(candidates[i]) <= 10^7)
        for (int bit = 0; bit < 24; ++bit) {
            int count = 0;
            
            // Count how many numbers have the current bit set
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            
            // Update the maximum size of a valid combination
            maxCombinationSize = max(maxCombinationSize, count);
        }
        
        return maxCombinationSize;
    }
};