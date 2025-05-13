class Solution {
public:
    static const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<vector<int>> dp(26, vector<int>(t + 1, -1));

        // Precompute all dp values
        for (int c = 0; c < 26; ++c) {
            dp[c][0] = 1; // Base case: 0 transformations, length is 1
        }

        // Bottom-up DP
        for (int step = 1; step <= t; ++step) {
            for (int c = 0; c < 26; ++c) {
                if (c == 25) { // 'z' case
                    dp[c][step] = (dp[0][step - 1] + dp[1][step - 1]) % MOD; // "ab"
                } else {
                    dp[c][step] = dp[c + 1][step - 1]; // Next character
                }
            }
        }

        // Now calculate final length
        long long result = 0;
        for (char ch : s) {
            result = (result + dp[ch - 'a'][t]) % MOD;
        }

        return (int)result;
    }
};