class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();

        // Step 1: Count total occurrences of each character
        vector<int> count(3, 0); // count[0] for 'a', count[1] for 'b', count[2] for 'c'
        for (char ch : s) {
            count[ch - 'a']++;
        }

        // If any character appears less than k times, it's impossible to satisfy the condition
        if (count[0] < k || count[1] < k || count[2] < k) return -1;

        // Step 2: Use a sliding window to find the longest substring we can keep
        int required_a = count[0] - k;
        int required_b = count[1] - k;
        int required_c = count[2] - k;

        int max_window_length = 0;
        vector<int> current_count(3, 0); // Current count of characters in the sliding window
        int left = 0;

        for (int right = 0; right < n; ++right) {
            current_count[s[right] - 'a']++;

            // Shrink the window if current counts exceed the required counts
            while (current_count[0] > required_a || current_count[1] > required_b || current_count[2] > required_c) {
                current_count[s[left] - 'a']--;
                left++;
            }

            // Update the maximum window length
            max_window_length = max(max_window_length, right - left + 1);
        }

        // Step 3: Calculate the minimum number of minutes
        return n - max_window_length;
    }
};