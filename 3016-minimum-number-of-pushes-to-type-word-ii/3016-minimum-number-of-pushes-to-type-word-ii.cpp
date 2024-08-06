class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        
        // Count frequency of each character
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort frequencies in descending order
        sort(freq.begin(), freq.end(), greater<int>());
        
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            
            // Calculate number of pushes for each character
            result += freq[i] * (1 + i / 8);
        }
        
        return result;
    }
};