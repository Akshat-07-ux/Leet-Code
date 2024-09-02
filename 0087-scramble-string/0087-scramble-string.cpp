class Solution {
public:
    unordered_map<string, bool> memo;
    
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;  // Base case: if both strings are equal
        if (s1.length() != s2.length()) return false;  // If lengths differ, return false
        
        string key = s1 + "_" + s2;  // Memoization key
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int n = s1.length();
        
        // Check if the two strings have the same set of characters
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return memo[key] = false;
        }
        
        // Try all possible splits
        for (int i = 1; i < n; i++) {
            // Case 1: Without swapping
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            
            // Case 2: With swapping
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }
        
        return memo[key] = false;  // If no match is found
    }
};