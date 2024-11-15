class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        // Continue until columnNumber becomes 0
        while (columnNumber > 0) {
            // Adjust for 1-indexed nature by subtracting 1
            columnNumber--;
            // Find the current character
            char ch = 'A' + (columnNumber % 26);
            // Append character to result
            result += ch;
            // Move to the next "digit"
            columnNumber /= 26;
        }
        
        // Reverse the result string as it was constructed backwards
        reverse(result.begin(), result.end());
        return result;
    }
};