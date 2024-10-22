class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        
        for (int num : nums) {
            // Update twos with bits that are in ones and the current number
            twos = twos | (ones & num);
            
            // XOR the current number with ones to update ones
            ones = ones ^ num;
            
            // Calculate common bits between ones and twos (bits that have appeared three times)
            int common = ones & twos;
            
            // Remove the common bits from ones and twos
            ones = ones & ~common;
            twos = twos & ~common;
        }
        
        // After all numbers are processed, ones contains the number that appeared exactly once
        return ones;
    }
};