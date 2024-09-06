class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;  // A string starting with '0' can't be decoded
        }

        // dp[i] will store the number of ways to decode the string up to index i-1
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // An empty string can be decoded in one way (doing nothing)
        dp[1] = (s[0] != '0') ? 1 : 0;  // If the first character is not '0', it can be decoded

        for (int i = 2; i <= n; i++) {
            // Check if the single digit at s[i-1] can be decoded
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Check if the two digits at s[i-2:i] can be decoded
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];  // The answer is stored in dp[n]
    }
};
