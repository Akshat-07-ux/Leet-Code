class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // Already equal

        vector<int> diffIndices;

        // Find indices where characters differ
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }

        // If there are exactly 2 differing positions, check if swapping makes them equal
        if (diffIndices.size() == 2) {
            int i = diffIndices[0], j = diffIndices[1];
            swap(s2[i], s2[j]);
            return s1 == s2;
        }

        // If there are more or less than 2 differences, return false
        return false;
    }
};