class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount; // Hash map to count occurrences of each word
        
        // Helper function to split a sentence into words and count them
        auto countWords = [&](string &s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                wordCount[word]++;
            }
        };

        // Count words in both sentences
        countWords(s1);
        countWords(s2);

        // Collect uncommon words (those that appear exactly once)
        vector<string> result;
        for (const auto &entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};