class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Convert wordDict to an unordered_set for O(1) lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        // DP array where dp[i] is true if s[0..i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // base case: empty string can always be segmented

        // Fill the dp array
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Check if the substring s[j..i-1] is in the dictionary and dp[j] is true
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;  // No need to check further if we found a valid segmentation
                }
            }
        }

        return dp[n];  // dp[n] tells if the whole string can be segmented
    }
};