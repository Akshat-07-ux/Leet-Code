class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());  // Store dictionary words in a set for O(1) lookups
        
        // DP array to store minimum extra characters for substring s[0:i]
        vector<int> dp(n + 1, 0);

        // Fill the DP array
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1; // Treat the ith character as extra by default
            
            // Check for all possible words ending at index i-1
            for (int j = i; j >= 1; j--) {
                string sub = s.substr(j - 1, i - j + 1);  // substring s[j-1:i-1]
                if (dict.find(sub) != dict.end()) {
                    dp[i] = min(dp[i], dp[j - 1]);  // If the substring is in the dictionary, update dp[i]
                }
            }
        }
        
        return dp[n];
    }
};