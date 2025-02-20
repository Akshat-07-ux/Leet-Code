class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end()); // Store existing numbers
        
        // Generate all binary strings of length n
        for (int i = 0; i < (1 << n); i++) {  // Iterate from 0 to 2^n - 1
            string binaryString = "";
            for (int j = n - 1; j >= 0; j--) {
                binaryString += ((i >> j) & 1) ? '1' : '0';  // Convert i to binary
            }
            if (numSet.find(binaryString) == numSet.end()) { // If missing, return it
                return binaryString;
            }
        }
        return ""; // Should never reach here
    }
};