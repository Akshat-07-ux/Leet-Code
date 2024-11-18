class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        // Case 1: If k == 0, return an array of zeroes
        if (k == 0) {
            return result;
        }
        
        // Case 2: If k > 0, calculate the sum of the next k elements
        if (k > 0) {
            int sum = 0;
            // Calculate the initial sum of the first k elements after index 0
            for (int i = 1; i <= k; i++) {
                sum += code[i % n];
            }
            // Fill the result array using the sliding window technique
            for (int i = 0; i < n; i++) {
                result[i] = sum;
                sum -= code[(i + 1) % n];
                sum += code[(i + k + 1) % n];
            }
        } else { // Case 3: If k < 0, calculate the sum of the previous |k| elements
            k = -k; // Convert k to positive for easier handling
            int sum = 0;
            // Calculate the initial sum of the first k elements before index 0
            for (int i = 1; i <= k; i++) {
                sum += code[(n - i) % n];
            }
            // Fill the result array using the sliding window technique
            for (int i = 0; i < n; i++) {
                result[i] = sum;
                sum -= code[(n + i - k) % n];
                sum += code[(n + i) % n];
            }
        }
        return result;
    }
};