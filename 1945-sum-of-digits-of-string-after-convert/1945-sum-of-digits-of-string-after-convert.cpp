class Solution {
public:
    int getLucky(string s, int k) {
        // Step 1: Convert the string to its numeric equivalent.
        string numStr = "";
        for (char c : s) {
            int num = c - 'a' + 1;
            numStr += to_string(num);
        }
        
        // Step 2: Perform the sum of digits k times.
        int result = 0;
        for (int i = 0; i < k; i++) {
            result = 0;
            for (char c : numStr) {
                result += c - '0';
            }
            numStr = to_string(result);
        }
        
        // Return the final result after k transformations.
        return result;
    }
};