class Solution {
public:
    int countSequences(vector<int>& freq) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {  // If the letter is available
                count++;  // Count the sequence
                freq[i]--;  // Use the letter
                count += countSequences(freq);  // Recurse for remaining letters
                freq[i]++;  // Backtrack
            }
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);  // Frequency array for A-Z
        for (char ch : tiles) {
            freq[ch - 'A']++;
        }
        return countSequences(freq);  // Start backtracking
    }
};