class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        // Process each character in the string
        for (char c : s) {
            if (isdigit(c)) {
                // Remove the closest non-digit character to the left
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                // Push non-digit characters onto the stack
                st.push(c);
            }
        }

        // Construct the resulting string from stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Reverse the string since the stack stores it in reverse order
        reverse(result.begin(), result.end());
        return result;
    }
};
