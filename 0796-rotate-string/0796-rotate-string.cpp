class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths are different, goal cannot be a rotation of s
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself
        string doubled = s + s;
        
        // Check if goal is a substring of doubled
        return doubled.find(goal) != string::npos;
    }
};