class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;

        if (words.empty()) return result;

        // Always include the first word
        result.push_back(words[0]);
        int prev_group = groups[0];

        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != prev_group) {
                result.push_back(words[i]);
                prev_group = groups[i];  // update the previous group
            }
        }

        return result;
    }
};