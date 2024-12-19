class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> s_to_t;
        unordered_set<char> mapped_chars;

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i], c2 = t[i];

            // Check if c1 is already mapped
            if (s_to_t.count(c1)) {
                // If the mapped character is not c2, return false
                if (s_to_t[c1] != c2) {
                    return false;
                }
            } else {
                // If c2 is already used for another mapping, return false
                if (mapped_chars.count(c2)) {
                    return false;
                }

                // Create a new mapping and mark c2 as used
                s_to_t[c1] = c2;
                mapped_chars.insert(c2);
            }
        }

        return true;
    }
};
