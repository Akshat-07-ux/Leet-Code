class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        
        // Check if the first and last characters of the entire sentence match
        if (sentence[0] != sentence[n - 1]) {
            return false;
        }

        // Iterate through the sentence to check if the last character of each word
        // matches the first character of the next word
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                // If there's a space, check if the last character of the current word
                // matches the first character of the next word
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }

        // If all checks passed, the sentence is circular
        return true;
    }
};