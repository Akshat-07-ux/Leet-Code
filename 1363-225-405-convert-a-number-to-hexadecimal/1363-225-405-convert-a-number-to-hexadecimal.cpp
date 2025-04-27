class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0"; // Special case for 0

        string hexChars = "0123456789abcdef";
        string result = "";

        // We need to handle negative numbers with two's complement automatically
        unsigned int n = num; // Cast to unsigned so negative numbers are treated correctly

        while (n > 0) {
            int hexDigit = n & 15; // Get the last 4 bits (0b1111 = 15)
            result = hexChars[hexDigit] + result; // Prepend the corresponding hex char
            n >>= 4; // Shift right by 4 bits
        }

        return result;
    }
};