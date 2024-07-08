class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisRecursive(n, n, "", result);
        return result;
    }

private:
    void generateParenthesisRecursive(int open, int close, string current, vector<string>& result) {
        // Base case: if we've used all parentheses, add the current string to the result
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        
        // If we have remaining opening parentheses, add one
        if (open > 0) {
            generateParenthesisRecursive(open - 1, close, current + "(", result);
        }
        
        // If we have more closing parentheses than opening ones, add a closing parenthesis
        if (close > open) {
            generateParenthesisRecursive(open, close - 1, current + ")", result);
        }
    }
};