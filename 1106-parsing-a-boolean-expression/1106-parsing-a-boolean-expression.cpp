class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        // Traverse the expression character by character
        for (char ch : expression) {
            if (ch == ',' || ch == '(') {
                // Ignore commas and opening parentheses
                continue;
            } else if (ch == 't' || ch == 'f' || ch == '&' || ch == '|' || ch == '!') {
                // Push true/false and operators to the stack
                st.push(ch);
            } else if (ch == ')') {
                // We encountered the end of a sub-expression
                evaluateExpression(st);
            }
        }
        
        // The final result will be the only element left in the stack
        return st.top() == 't';
    }

private:
    void evaluateExpression(stack<char>& st) {
        // Vector to collect all values inside the current sub-expression
        vector<char> values;

        // Pop all characters until we find the opening operator
        while (!st.empty() && st.top() != '&' && st.top() != '|' && st.top() != '!') {
            values.push_back(st.top());
            st.pop();
        }

        // Pop the operator (it must be & or | or !)
        char op = st.top();
        st.pop();
        
        char result;
        
        if (op == '&') {
            // AND operator: all values must be 't' to return 't'
            result = 't';
            for (char val : values) {
                if (val == 'f') {
                    result = 'f';
                    break;
                }
            }
        } else if (op == '|') {
            // OR operator: at least one value must be 't' to return 't'
            result = 'f';
            for (char val : values) {
                if (val == 't') {
                    result = 't';
                    break;
                }
            }
        } else if (op == '!') {
            // NOT operator: flip the single value
            result = (values[0] == 't') ? 'f' : 't';
        }
        
        // Push the result back to the stack
        st.push(result);
    }
};