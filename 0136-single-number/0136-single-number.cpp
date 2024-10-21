class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // XOR all elements in the array
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
};