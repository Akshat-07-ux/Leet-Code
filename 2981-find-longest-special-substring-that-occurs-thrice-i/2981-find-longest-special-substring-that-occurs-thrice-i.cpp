class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        
        // Iterate over possible lengths of special substrings
        for (int len = n; len >= 1; --len) {
            unordered_map<string, int> freqMap;
            
            // Generate substrings of length `len`
            for (int i = 0; i <= n - len; ++i) {
                string substring = s.substr(i, len);
                
                // Check if the substring is "special"
                if (isSpecial(substring)) {
                    freqMap[substring]++;
                    
                    // If the substring occurs at least 3 times, return its length
                    if (freqMap[substring] >= 3) {
                        return len;
                    }
                }
            }
        }
        
        return -1; // No valid special substring found
    }
    
private:
    // Helper function to check if a string is "special"
    bool isSpecial(const string &str) {
        char firstChar = str[0];
        for (char c : str) {
            if (c != firstChar) {
                return false;
            }
        }
        return true;
    }
};