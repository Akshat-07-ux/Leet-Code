class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Construct the new string with the reverse of s and a separator
        string temp = s + "#" + rev_s;
        
        // Create LPS array (Longest Prefix Suffix)
        vector<int> lps(temp.size(), 0);
        
        // Build the LPS array for the temp string
        for (int i = 1; i < temp.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // lps.back() gives the length of the longest palindromic prefix
        int longest_palindromic_prefix_len = lps.back();
        
        // Add the remaining characters from the reverse string to the front
        string to_add = rev_s.substr(0, s.size() - longest_palindromic_prefix_len);
        
        return to_add + s;
    }
};