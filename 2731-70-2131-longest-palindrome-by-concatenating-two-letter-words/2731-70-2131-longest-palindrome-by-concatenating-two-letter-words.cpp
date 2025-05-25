class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int length = 0;
        bool hasCentral = false;

        // Count occurrences of each word
        for (const string& word : words) {
            count[word]++;
        }

        for (auto& [word, freq] : count) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            // Case 1: word is palindromic (like "gg")
            if (word == rev) {
                // Use as many pairs as possible
                length += (freq / 2) * 4;
                if (freq % 2 == 1) hasCentral = true;
            }
            // Case 2: word and its reverse are different (like "ab" and "ba")
            else if (count.find(rev) != count.end()) {
                int pairs = min(freq, count[rev]);
                length += pairs * 4;
                count[rev] = 0; // Mark reverse word as used
                count[word] = 0; // Mark current word as used
            }
        }

        // If any palindromic word remains, one can be placed in center
        if (hasCentral) length += 2;

        return length;
    }
};
