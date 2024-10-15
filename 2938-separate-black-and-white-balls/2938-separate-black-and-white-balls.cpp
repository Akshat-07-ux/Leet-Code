class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        int n = s.length();
        int right = n - 1;  // Right pointer starts from the end

        // Iterate from right to left
        for (int left = n - 1; left >= 0; left--) {
            if (s[left] == '1') {
                // If we find a black ball, calculate the steps needed to move it to the rightmost available position
                steps += right - left;
                right--;  // Move the right pointer to the next available position
            }
        }

        return steps;
    }
};