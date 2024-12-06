class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Step 1: Add banned numbers to a set for quick lookup
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        int count = 0;   // To store the number of integers chosen
        int currentSum = 0; // To track the sum of chosen integers
        
        // Step 2: Iterate through the range [1, n]
        for (int i = 1; i <= n; ++i) {
            // Skip banned numbers
            if (bannedSet.find(i) != bannedSet.end()) continue;
            
            // Check if adding the current number exceeds maxSum
            if (currentSum + i > maxSum) break;
            
            // Otherwise, add the number and increment the count
            currentSum += i;
            count++;
        }
        
        return count;
    }
};