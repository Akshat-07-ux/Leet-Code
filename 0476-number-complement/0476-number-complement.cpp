class Solution {
public:
    int findComplement(int num) {
        // Calculate the number of bits in the binary representation of num
        int mask = 0;
        int temp = num;
        
        // Create a mask with all bits set to 1 that has the same length as the binary representation of num
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        
        // XOR the num with the mask to flip all the bits
        return num ^ mask;
    }
};