class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        // Create a set of allowed characters for quick lookup
        std::unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        
        int count = 0;
        
        // Iterate through each word in the words vector
        for (const std::string& word : words) {
            bool isConsistent = true;
            
            // Check each character in the word
            for (char ch : word) {
                if (allowedSet.find(ch) == allowedSet.end()) {
                    // If character not in allowedSet, this word is not consistent
                    isConsistent = false;
                    break;
                }
            }
            
            // Increment count if the word is consistent
            if (isConsistent) {
                ++count;
            }
        }
        
        return count;
    }
};