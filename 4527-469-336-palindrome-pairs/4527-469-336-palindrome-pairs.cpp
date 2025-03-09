class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordMap;
        vector<vector<int>> result;
        
        // Store words in a hashmap with their index
        for (int i = 0; i < words.size(); i++) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            wordMap[reversedWord] = i;
        }

        // Iterate over each word to check palindrome pairs
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int len = word.size();

            for (int j = 0; j <= len; j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);

                // Check if left part is a palindrome and right reversed exists
                if (isPalindrome(left) && wordMap.count(right) && wordMap[right] != i) {
                    result.push_back({wordMap[right], i});
                }

                // Check if right part is a palindrome and left reversed exists (avoid duplicate for empty string)
                if (!right.empty() && isPalindrome(right) && wordMap.count(left) && wordMap[left] != i) {
                    result.push_back({i, wordMap[left]});
                }
            }
        }
        
        return result;
    }

private:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};