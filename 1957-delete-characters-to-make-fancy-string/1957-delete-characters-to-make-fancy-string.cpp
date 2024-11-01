class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int consecutiveCount = 1;  // Track consecutive characters
        
        result += s[0];  // Add the first character to the result
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1;
            }
            
            // Append character if it doesn't form three consecutive same characters
            if (consecutiveCount < 3) {
                result += s[i];
            }
        }
        
        return result;
    }
};