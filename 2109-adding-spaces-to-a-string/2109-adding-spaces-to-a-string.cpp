class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int n = s.size(), m = spaces.size();
        int j = 0; // Pointer for the spaces array

        for (int i = 0; i < n; ++i) {
            // If the current index matches the space position, add a space
            if (j < m && i == spaces[j]) {
                result += ' ';
                ++j;
            }
            result += s[i];
        }

        return result;
    }
};