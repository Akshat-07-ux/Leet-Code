class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit and process the carry
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0; // set the current digit to 0 if it was 9
        }
        
        // If all digits were 9, we need to add a new leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};