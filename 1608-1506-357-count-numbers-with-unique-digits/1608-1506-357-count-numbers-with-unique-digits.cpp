class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1; // Only "0" is valid
        
        int count = 1; // Count for n = 0
        int uniqueNumbers = 9, availableDigits = 9;
        
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                count += uniqueNumbers; // Count for single-digit numbers
            } else {
                uniqueNumbers *= availableDigits; // Compute unique combinations
                availableDigits--;
                count += uniqueNumbers;
            }
        }
        
        return count;
    }
};