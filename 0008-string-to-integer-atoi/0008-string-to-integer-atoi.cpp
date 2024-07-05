class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long result = 0;
        
        // Step 1: Ignore leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check for sign
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert digits
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Check for overflow
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return static_cast<int>(result * sign);
    }
};