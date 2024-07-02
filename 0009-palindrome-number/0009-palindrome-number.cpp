class Solution {
public:
    bool isPalindrome(int x) {
        // Handle negative numbers and numbers ending in zero (except zero itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        // If the number of digits is odd, we can ignore the middle digit
        // For even digits, x will equal reversed if it's a palindrome
        return x == reversed || x == reversed / 10;
    }
};