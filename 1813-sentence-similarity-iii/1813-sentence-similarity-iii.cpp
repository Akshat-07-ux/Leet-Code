class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split both sentences into words
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        // Ensure words1 is the smaller or equal in length sentence
        if (words1.size() > words2.size()) {
            swap(words1, words2);
        }
        
        int n1 = words1.size();
        int n2 = words2.size();
        int i = 0, j = 0;
        
        // Check for matching prefix
        while (i < n1 && words1[i] == words2[i]) {
            i++;
        }
        
        // Check for matching suffix
        while (j < n1 && words1[n1 - j - 1] == words2[n2 - j - 1]) {
            j++;
        }
        
        // The two sentences are similar if the sum of matching prefix and suffix covers the smaller sentence
        return (i + j) >= n1;
    }
    
private:
    // Helper function to split the sentence into words
    vector<string> split(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};