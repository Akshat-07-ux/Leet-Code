class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        
        // Table to store if a substring s[i...j] is a palindrome
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        // Table to store the minimum cuts needed for substring s[0...i]
        vector<int> cuts(n);
        
        // Build the isPalindrome table and calculate the cuts
        for (int i = 0; i < n; i++) {
            cuts[i] = i;  // Max cuts (worst case)
            
            for (int j = 0; j <= i; j++) {
                // Check if s[j...i] is a palindrome
                if (s[j] == s[i] && (i - j <= 1 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                    
                    // If s[j...i] is a palindrome, update cuts[i]
                    if (j == 0) {
                        cuts[i] = 0;  // No cut needed if the whole substring s[0...i] is a palindrome
                    } else {
                        cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                    }
                }
            }
        }
        
        return cuts[n - 1];
    }
};