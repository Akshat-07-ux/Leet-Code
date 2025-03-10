class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        
        vector<int> count(N + 1, 0);
        int repeated = -1, missing = -1;

        // Count occurrences of each number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }

        // Identify repeated and missing numbers
        for (int i = 1; i <= N; i++) {
            if (count[i] == 2) repeated = i;
            if (count[i] == 0) missing = i;
        }

        return {repeated, missing};
    }
};