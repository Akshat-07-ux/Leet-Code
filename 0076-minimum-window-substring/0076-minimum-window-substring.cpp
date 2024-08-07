class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.length() < t.length()) {
            return "";
        }

        // Frequency map for characters in t
        std::unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }

        // Frequency map for the current window in s
        std::unordered_map<char, int> windowFreq;
        int required = tFreq.size();
        int formed = 0;

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        
        while (r < s.length()) {
            // Add character from the right to the window
            char c = s[r];
            windowFreq[c]++;
            if (tFreq.find(c) != tFreq.end() && windowFreq[c] == tFreq[c]) {
                formed++;
            }

            // Try and contract the window until it ceases to be valid
            while (l <= r && formed == required) {
                // Update minimum length window if needed
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minLeft = l;
                }

                // Remove character from the left of the window
                char c2 = s[l];
                windowFreq[c2]--;
                if (tFreq.find(c2) != tFreq.end() && windowFreq[c2] < tFreq[c2]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};