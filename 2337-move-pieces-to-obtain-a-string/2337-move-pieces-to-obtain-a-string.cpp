class Solution {
public:
    bool canChange(string start, string target) {
        // Remove all underscores and compare the order of 'L' and 'R'
        string startNoUnderscore, targetNoUnderscore;
        for (char c : start) {
            if (c != '_') startNoUnderscore += c;
        }
        for (char c : target) {
            if (c != '_') targetNoUnderscore += c;
        }
        if (startNoUnderscore != targetNoUnderscore) return false;

        // Two pointer approach to check movement feasibility
        int n = start.size();
        int i = 0, j = 0;

        while (i < n && j < n) {
            // Find the next 'L' or 'R' in start
            while (i < n && start[i] == '_') i++;
            // Find the next 'L' or 'R' in target
            while (j < n && target[j] == '_') j++;

            // If one reaches the end before the other
            if (i == n || j == n) return i == n && j == n;

            // The character in both strings must match
            if (start[i] != target[j]) return false;

            // Check movement constraints
            if (start[i] == 'L' && i < j) return false; // 'L' can't move to the right
            if (start[i] == 'R' && i > j) return false; // 'R' can't move to the left

            // Move to the next characters
            i++;
            j++;
        }

        return true;
    }
};