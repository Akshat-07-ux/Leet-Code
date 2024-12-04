class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {
            // Extract the rightmost bit of n
            uint32_t bit = n & 1;

            // Shift result to the left and add the extracted bit
            result = (result << 1) | bit;

            // Shift n to the right to process the next bit
            n >>= 1;
        }

        return result;
    }
};