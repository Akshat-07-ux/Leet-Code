class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen; // To store sequences we have already seen
        unordered_set<string> repeated; // To store sequences that are repeated
        int n = s.length();

        // If the string length is less than 10, no repeated 10-letter sequences can exist
        if (n < 10) return {};

        for (int i = 0; i <= n - 10; ++i) {
            string sequence = s.substr(i, 10); // Get the 10-letter sequence starting at index i

            // If we have already seen this sequence, it's repeated, so add it to the repeated set
            if (seen.find(sequence) != seen.end()) {
                repeated.insert(sequence);
            } else {
                seen.insert(sequence);
            }
        }

        // Convert the repeated set to a vector and return it
        return vector<string>(repeated.begin(), repeated.end());
    }
};