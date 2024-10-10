class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in the wordList, no possible transformation
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q; // Pair of (current word, transformation sequence length)
        q.push({beginWord, 1});     // Start BFS from beginWord with length 1
        
        while (!q.empty()) {
            auto [currentWord, length] = q.front();
            q.pop();
            
            // Try changing each character in the current word
            for (int i = 0; i < currentWord.size(); ++i) {
                string tempWord = currentWord;
                
                // Try all possible character replacements
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    tempWord[i] = ch;
                    
                    // If this transformation leads to endWord, return the answer
                    if (tempWord == endWord) {
                        return length + 1;
                    }
                    
                    // If this transformed word is in the wordSet, add it to the queue and remove it from the set
                    if (wordSet.find(tempWord) != wordSet.end()) {
                        q.push({tempWord, length + 1});
                        wordSet.erase(tempWord); // Mark this word as visited
                    }
                }
            }
        }
        
        // No transformation sequence found
        return 0;
    }
};