class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string a = "ab";
        string b = "ba";
        int points_a = x;
        int points_b = y;
        
        // If removing "ba" gives more points, we prioritize it
        if (y > x) {
            swap(a, b);
            swap(points_a, points_b);
        }
        
        return removeSubstrings(s, a, b, points_a, points_b);
    }
    
private:
    int removeSubstrings(const string& s, const string& a, const string& b, int points_a, int points_b) {
        int total_points = 0;
        string stack;
        
        // First pass: remove the higher-priority substring
        for (char c : s) {
            if (!stack.empty() && stack.back() == a[0] && c == a[1]) {
                stack.pop_back();
                total_points += points_a;
            } else {
                stack.push_back(c);
            }
        }
        
        string new_stack;
        
        // Second pass: remove the lower-priority substring
        for (char c : stack) {
            if (!new_stack.empty() && new_stack.back() == b[0] && c == b[1]) {
                new_stack.pop_back();
                total_points += points_b;
            } else {
                new_stack.push_back(c);
            }
        }
        
        return total_points;
    }
};