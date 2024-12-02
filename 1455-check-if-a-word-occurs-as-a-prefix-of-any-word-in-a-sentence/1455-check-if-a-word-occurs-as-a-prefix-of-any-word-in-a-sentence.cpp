class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string word;
        int index = 1; // Words are 1-indexed
        
        // Traverse each word in the sentence
        while (ss >> word) {
            if (word.find(searchWord) == 0) { // Check if searchWord is a prefix
                return index;
            }
            index++;
        }
        
        return -1; // If no word matches
    }
};