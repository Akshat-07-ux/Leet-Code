class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        
        // Calculate the total sum required for all n + m rolls
        int totalSum = mean * (n + m);
        
        // Calculate the sum of the observed rolls
        int observedSum = accumulate(rolls.begin(), rolls.end(), 0);
        
        // Calculate the sum of the missing rolls
        int missingSum = totalSum - observedSum;
        
        // Check if it's possible to distribute the missing sum among n rolls
        if (missingSum < n || missingSum > 6 * n) {
            return {};  // Return an empty array if not possible
        }
        
        // Create a result array to store the missing rolls
        vector<int> result(n, 1);  // Start by assigning 1 to all missing rolls
        
        missingSum -= n;  // Subtract 1 from each of the n rolls

        // Distribute the remaining sum as evenly as possible
        for (int i = 0; i < n && missingSum > 0; i++) {
            int add = min(5, missingSum);  // Add up to 5 to each roll (since each roll can be at most 6)
            result[i] += add;
            missingSum -= add;
        }
        
        return result;
    }
};