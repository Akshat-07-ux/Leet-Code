class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false; // Negative numbers and zero are not powers of 3

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};