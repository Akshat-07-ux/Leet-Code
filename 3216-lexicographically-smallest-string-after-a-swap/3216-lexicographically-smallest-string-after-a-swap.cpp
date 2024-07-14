class Solution {
public:
    std::string getSmallestString(std::string s) {
        int n = s.size();
        
        // Iterate through the string to find adjacent digits with the same parity
        for (int i = 0; i < n - 1; ++i) {
            // Check if the current digit and the next digit have the same parity
            if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2) {
                // Swap if it results in a lexicographically smaller string
                if (s[i] > s[i + 1]) {
                    std::swap(s[i], s[i + 1]);
                    break; // Only one swap allowed
                }
            }
        }

        return s;
    }
};