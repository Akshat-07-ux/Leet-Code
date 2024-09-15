class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Map to store the first occurrence of each bitmask
        unordered_map<int, int> maskToIndex;
        
        // Initialize with mask 0 at index -1
        maskToIndex[0] = -1;
        
        int mask = 0; // Current bitmask
        int maxLength = 0;
        
        // Iterate over the string
        for (int i = 0; i < s.length(); ++i) {
            // Update the bitmask for each vowel
            if (s[i] == 'a') {
                mask ^= (1 << 0);
            } else if (s[i] == 'e') {
                mask ^= (1 << 1);
            } else if (s[i] == 'i') {
                mask ^= (1 << 2);
            } else if (s[i] == 'o') {
                mask ^= (1 << 3);
            } else if (s[i] == 'u') {
                mask ^= (1 << 4);
            }
            
            // If this mask has been seen before, calculate the length of the substring
            if (maskToIndex.count(mask)) {
                maxLength = max(maxLength, i - maskToIndex[mask]);
            } else {
                // Store the first occurrence of this mask
                maskToIndex[mask] = i;
            }
        }
        
        return maxLength;
    }
};