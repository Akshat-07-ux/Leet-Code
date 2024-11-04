class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        
        int count = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && word[i] == word[i - 1]) {
                count++;
                // If we reach 9 consecutive characters, add them to the result
                if (count == 9) {
                    comp += to_string(count) + word[i - 1];
                    count = 0;
                }
            } else {
                if (count > 0) {
                    comp += to_string(count) + word[i - 1];
                }
                count = 1;
            }
        }
        
        return comp;
    }
};