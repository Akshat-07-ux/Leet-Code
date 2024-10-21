class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstrings;  // To store the unique substrings
        return backtrack(s, 0, uniqueSubstrings);
    }
    
private:
    int backtrack(const string& s, int start, unordered_set<string>& uniqueSubstrings) {
        if (start == s.size()) {
            return 0;  // Base case: If we've processed the entire string, return 0
        }
        
        int maxSplits = 0;
        
        // Try all possible splits starting from index 'start'
        string currentSubstring = "";
        for (int i = start; i < s.size(); ++i) {
            currentSubstring += s[i];
            
            // If this substring is not used, explore further
            if (uniqueSubstrings.find(currentSubstring) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(currentSubstring);
                
                // Recursively explore the remaining part of the string and find max splits
                int splits = 1 + backtrack(s, i + 1, uniqueSubstrings);
                
                // Track the maximum number of splits
                maxSplits = max(maxSplits, splits);
                
                // Backtrack: remove the substring and try other splits
                uniqueSubstrings.erase(currentSubstring);
            }
        }
        
        return maxSplits;
    }
};