class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;  // Counts unmatched '('
        int close_count = 0; // Counts unmatched ')'
        
        for (char c : s) {
            if (c == '(') {
                open_count++;
            } else if (c == ')') {
                if (open_count > 0) {
                    // We have an unmatched '(' to match this ')'
                    open_count--;
                } else {
                    // No unmatched '(' to match this ')'
                    close_count++;
                }
            }
        }
        
        // Total unmatched parentheses is the sum of unmatched '(' and ')'
        return open_count + close_count;
    }
};