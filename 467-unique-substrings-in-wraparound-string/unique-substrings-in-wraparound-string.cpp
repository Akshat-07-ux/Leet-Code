class Solution {
public:
    int findSubstringInWraproundString(string s) {
        if (s.empty()) return 0;

        vector<int> maxLen(26, 0); // max length of substring ending with each letter
        int k = 0; // current length of valid consecutive substring

        for (int i = 0; i < s.size(); ++i) {
            // Check if current character continues a consecutive sequence
            if (i > 0 && ((s[i] - s[i - 1] + 26) % 26 == 1)) {
                k++;
            } else {
                k = 1;
            }

            int idx = s[i] - 'a';
            maxLen[idx] = max(maxLen[idx], k);
        }

        // Sum of all maximum lengths is the count of unique substrings
        int total = 0;
        for (int len : maxLen) {
            total += len;
        }

        return total;
    }
};