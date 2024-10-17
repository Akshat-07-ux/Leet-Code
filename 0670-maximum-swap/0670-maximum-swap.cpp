class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string to manipulate digits
        string numStr = to_string(num);
        int n = numStr.size();
        
        // Create a vector to store the index of the last occurrence of each digit (0-9)
        vector<int> last(10, -1);
        
        // Record the last index of each digit in the number
        for (int i = 0; i < n; i++) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse the number and try to find a larger digit to swap with
        for (int i = 0; i < n; i++) {
            // Check digits larger than numStr[i] and see if they occur later
            for (int d = 9; d > numStr[i] - '0'; d--) {
                if (last[d] > i) {
                    // Swap the digits
                    swap(numStr[i], numStr[last[d]]);
                    // Convert the string back to an integer and return
                    return stoi(numStr);
                }
            }
        }
        
        // If no swap was performed, return the original number
        return num;
    }
};