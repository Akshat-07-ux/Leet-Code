class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0'); // build the number, could be >9
            }
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            }
            else if (c == ']') {
                int repeat = countStack.top(); countStack.pop();
                string temp = stringStack.top(); stringStack.pop();
                while (repeat--) {
                    temp += currentString;
                }
                currentString = temp;
            }
            else {
                currentString += c;
            }
        }

        return currentString;
    }
};