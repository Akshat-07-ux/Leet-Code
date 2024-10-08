class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0; // To track the imbalance of closing brackets
        int maxImbalance = 0; // To track the maximum imbalance during the traversal
        
        // Traverse the string
        for (char c : s) {
            if (c == '[') {
                imbalance--; // Each '[' decreases imbalance
            } else {
                imbalance++; // Each ']' increases imbalance
            }
            // Track the maximum imbalance
            maxImbalance = max(maxImbalance, imbalance);
        }
        
        // Minimum swaps is half the maximum imbalance
        return (maxImbalance + 1) / 2;
    }
};