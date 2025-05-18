class Solution {
public:
    const int MOD = 1e9 + 7;

    void generateValidCols(int m, int col, int prev, int mask, vector<int>& validCols) {
        if (col == m) {
            validCols.push_back(mask);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (color != prev) {
                generateValidCols(m, col + 1, color, mask * 3 + color, validCols);
            }
        }
    }

    bool isCompatible(int a, int b, int m) {
        for (int i = 0; i < m; ++i) {
            if ((a % 3) == (b % 3)) return false;
            a /= 3;
            b /= 3;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        vector<int> validCols;
        generateValidCols(m, 0, -1, 0, validCols);

        int size = validCols.size();
        vector<vector<int>> compatible(size);

        // Build compatibility list
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (isCompatible(validCols[i], validCols[j], m)) {
                    compatible[i].push_back(j);
                }
            }
        }

        // DP: dp[col][stateIndex]
        vector<int> dp(size, 1); // First column: all valid states count as 1

        for (int col = 1; col < n; ++col) {
            vector<int> newDp(size, 0);
            for (int i = 0; i < size; ++i) {
                for (int j : compatible[i]) {
                    newDp[i] = (newDp[i] + dp[j]) % MOD;
                }
            }
            dp = std::move(newDp); // Fully qualified move to avoid warning
        }

        // Sum all valid configurations for the last column
        int result = 0;
        for (int count : dp) result = (result + count) % MOD;

        return result;
    }
};