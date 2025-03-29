class Solution {
public:
    const int MOD = 1337;

    // Function to compute (x^y) % mod using fast exponentiation
    int modPower(int x, int y) {
        int res = 1;
        x %= MOD; // Take mod to keep values small
        
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % MOD; // Multiply result when y is odd
            }
            x = (x * x) % MOD; // Square the base
            y /= 2; // Divide exponent by 2
        }
        return res;
    }

    // Function to compute a^b mod 1337
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1; // Base case

        int lastDigit = b.back();
        b.pop_back();

        // Recursive formula: (a^b[:-1])^10 * (a^lastDigit) % 1337
        int part1 = modPower(superPow(a, b), 10) % MOD;
        int part2 = modPower(a, lastDigit) % MOD;
        
        return (part1 * part2) % MOD;
    }
};