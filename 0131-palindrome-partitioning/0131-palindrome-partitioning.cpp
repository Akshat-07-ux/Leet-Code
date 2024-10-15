class Solution {
public:
    // Function to check if a substring is a palindrome
    bool isPalindrome(const std::string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    // Backtracking function to find all partitions
    void backtrack(std::string& s, int start, std::vector<std::string>& currentPartition, std::vector<std::vector<std::string>>& result) {
        // If we reach the end of the string, add the current partition to the result
        if (start >= s.size()) {
            result.push_back(currentPartition);
            return;
        }

        // Try partitioning the string at each possible position
        for (int i = start; i < s.size(); i++) {
            // If the substring s[start:i+1] is a palindrome
            if (isPalindrome(s, start, i)) {
                // Include this palindrome in the current partition
                currentPartition.push_back(s.substr(start, i - start + 1));
                
                // Recur for the remaining part of the string
                backtrack(s, i + 1, currentPartition, result);

                // Backtrack by removing the last added palindrome
                currentPartition.pop_back();
            }
        }
    }

    // Main function to return all palindrome partitions
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> currentPartition;
        backtrack(s, 0, currentPartition, result);
        return result;
    }
};