class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Move the left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move the right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare the characters after converting to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            // Move pointers inward
            left++;
            right--;
        }
        
        return true;
    }
};