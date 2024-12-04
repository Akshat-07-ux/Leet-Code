class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int i = 0, j = 0;

        // Traverse str1 and str2
        while (i < n && j < m) {
            // Check if str1[i] matches str2[j] directly or after a cyclic increment
            if (str1[i] == str2[j] || (str1[i] + 1 - 'a') % 26 + 'a' == str2[j]) {
                j++; // Move to the next character in str2
            }
            i++; // Move to the next character in str1
        }

        // If we matched all characters of str2, return true
        return j == m;
    }
};