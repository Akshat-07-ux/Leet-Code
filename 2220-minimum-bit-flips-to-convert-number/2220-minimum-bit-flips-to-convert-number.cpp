class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR start and goal to find positions where bits differ
        int xorResult = start ^ goal;
        
        // Count the number of set bits (1s) in the xorResult
        int count = 0;
        while (xorResult > 0) {
            // If the least significant bit is 1, increment the count
            count += xorResult & 1;
            // Shift the result right to check the next bit
            xorResult >>= 1;
        }
        
        return count;
    }
};