class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        // If the combination is of size k, add it to the result
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        // Iterate through all numbers from start to n
        for (int i = start; i <= n; ++i) {
            // Add the current number to the combination
            current.push_back(i);
            // Recursively call backtrack to add the next number
            backtrack(i + 1, n, k, current, result);
            // Remove the last added number to backtrack
            current.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        // Start backtracking with the first number as 1
        backtrack(1, n, k, current, result);
        return result;
    }
};