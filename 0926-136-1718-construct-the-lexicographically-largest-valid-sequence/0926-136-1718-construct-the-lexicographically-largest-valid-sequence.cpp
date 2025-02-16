class Solution {
public:
    vector<int> res; // The result array
    vector<bool> used; // To track used numbers
    int n; // Given n

    bool backtrack(int index) {
        if (index == res.size()) return true; // If all positions are filled, return success
        if (res[index] != 0) return backtrack(index + 1); // Skip already filled positions

        for (int num = n; num >= 1; --num) { // Try larger numbers first for lexicographic order
            if (used[num]) continue; // Skip used numbers
            if (num == 1) { // 1 only appears once
                res[index] = 1;
                used[num] = true;
                if (backtrack(index + 1)) return true;
                res[index] = 0;
                used[num] = false;
            } else { // Other numbers appear twice
                if (index + num >= res.size() || res[index + num] != 0) continue; // Check valid placement

                // Place the number
                res[index] = res[index + num] = num;
                used[num] = true;

                // Recur to the next position
                if (backtrack(index + 1)) return true;

                // Backtrack
                res[index] = res[index + num] = 0;
                used[num] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        this->n = n;
        int size = 2 * n - 1; // Length of sequence
        res.assign(size, 0); // Initialize result array with 0
        used.assign(n + 1, false); // Track used numbers
        backtrack(0);
        return res;
    }
};
