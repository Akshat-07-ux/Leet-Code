class Solution {
public:
    int minLength(string s) {
        // Stack to store characters
        stack<char> st;
        
        // Traverse through the string
        for (char c : s) {
            // If the top of the stack forms "AB" or "CD" with the current character, pop it
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                st.pop();  // Remove the matching pair
            } else {
                st.push(c);  // Push the current character onto the stack
            }
        }
        
        // The size of the stack is the minimum possible length
        return st.size();
    }
};