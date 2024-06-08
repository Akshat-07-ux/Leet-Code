#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1; // Move the start right after the previous occurrence
            }

            charIndexMap[currentChar] = i; // Update the last seen index of the character
            maxLength = std::max(maxLength, i - start + 1); // Calculate the max length of the substring
        }

        return maxLength;
    }
};

