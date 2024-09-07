class Solution {
public:
    // Helper function to check if a segment of the IP address is valid
    bool isValid(const string &s) {
        // Check if the segment is non-empty, less than or equal to 255, and doesn't have leading zeros
        if (s.length() > 1 && s[0] == '0') return false; // Leading zero
        int num = stoi(s); // Convert string to integer
        return num >= 0 && num <= 255;
    }

    // Backtracking function to restore IP addresses
    void backtrack(string &s, int idx, int dots, string currentIP, vector<string> &result) {
        // Base case: if we've placed 3 dots and we're at the end of the string, add the IP address
        if (dots == 3) {
            string lastSegment = s.substr(idx);
            if (isValid(lastSegment)) {
                currentIP += lastSegment; // Complete the IP address
                result.push_back(currentIP);
            }
            return;
        }

        // Try placing the dot at every position from idx to the next 3 characters (since the max segment length is 3)
        for (int i = 1; i <= 3 && idx + i < s.length(); ++i) {
            string segment = s.substr(idx, i);
            if (isValid(segment)) {
                backtrack(s, idx + i, dots + 1, currentIP + segment + ".", result);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.length() < 4 || s.length() > 12) return result; // Early exit if the string length is invalid

        backtrack(s, 0, 0, "", result); // Start backtracking from the first index
        return result;
    }
};