class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Fast power function: (base^exp) % MOD
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2; // positions with even indices
        long long oddPos = n / 2;        // positions with odd indices

        long long evenCount = modPow(5, evenPos, MOD); // 5 choices for even positions
        long long oddCount = modPow(4, oddPos, MOD);   // 4 choices for odd positions

        return (evenCount * oddCount) % MOD;
    }
};