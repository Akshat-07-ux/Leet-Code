class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1); // Check the least significant bit
            n >>= 1;         // Right shift n by 1 to process the next bit
        }
        return count;
    }
};