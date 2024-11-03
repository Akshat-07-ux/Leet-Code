class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Ensure there are at least two operands
                if (stack.size() < 2) {
                    throw std::invalid_argument("Not enough operands in the stack.");
                }

                // Pop the top two operands
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();

                int result;
                if (token == "+") {
                    result = a + b;
                } else if (token == "-") {
                    result = a - b;
                } else if (token == "*") {
                    result = a * b;
                } else if (token == "/") {
                    // Perform integer division, truncating towards zero
                    result = (a / b); // C++ automatically truncates towards zero
                }
                
                // Push the result back onto the stack
                stack.push(result);
            } else {
                // If it's a number, convert and push to the stack
                stack.push(std::stoi(token));
            }
        }

        // The result should be the only element in the stack
        if (stack.size() != 1) {
            throw std::invalid_argument("Invalid expression.");
        }
        
        return stack.top();
    }
};