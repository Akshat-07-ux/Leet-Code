class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int idealArrays(int n, int maxValue) {
        // Step 1: Compute all divisors efficiently
        vector<vector<int>> divisors(maxValue + 1);
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = i * 2; j <= maxValue; j += i) {
                divisors[j].push_back(i);
            }
        }

        // Step 2: DP initialization
        int maxLen = min(n, 14); // Because with n=10000, depth of divisibility is low (~13 max)
        vector<vector<int>> dp(maxValue + 1, vector<int>(maxLen + 1, 0));

        for (int i = 1; i <= maxValue; ++i) {
            dp[i][1] = 1;
        }

        for (int len = 2; len <= maxLen; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int d : divisors[i]) {
                    dp[i][len] = (dp[i][len] + dp[d][len - 1]) % MOD;
                }
            }
        }

        // Step 3: Precompute C(n-1, k-1)
        vector<vector<int>> comb(n + 1, vector<int>(maxLen + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= maxLen && j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // Step 4: Count all valid sequences
        long long result = 0;
        for (int val = 1; val <= maxValue; ++val) {
            for (int len = 1; len <= maxLen; ++len) {
                result = (result + 1LL * dp[val][len] * comb[n - 1][len - 1]) % MOD;
            }
        }

        return result;
    }
};