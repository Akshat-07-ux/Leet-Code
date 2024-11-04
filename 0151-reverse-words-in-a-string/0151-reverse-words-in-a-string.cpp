class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Use a stringstream to split the words
        stringstream ss(s);
        string word;
        vector<string> words;
        
        // Extract words and store in the vector
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Step 2: Reverse the order of words
        reverse(words.begin(), words.end());
        
        // Step 3: Join words with a single space in between
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        
        return result;
    }
};