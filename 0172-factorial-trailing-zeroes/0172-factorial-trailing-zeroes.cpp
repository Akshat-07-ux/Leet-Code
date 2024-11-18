class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        // Count the number of factors of 5
        while (n > 0) {
            n /= 5;
            count += n;
        }
        return count;
    }
};