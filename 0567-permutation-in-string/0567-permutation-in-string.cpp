class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        
        // If s1 is longer than s2, it's impossible for s2 to contain a permutation of s1
        if (n1 > n2) return false;
        
        // Frequency array for s1 and the current window in s2
        vector<int> freq1(26, 0), freq2(26, 0);
        
        // Fill frequency array for s1 and first window of s2
        for (int i = 0; i < n1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        // Check for the first window
        if (freq1 == freq2) return true;
        
        // Slide the window over s2
        for (int i = n1; i < n2; i++) {
            // Add the current character in the window
            freq2[s2[i] - 'a']++;
            // Remove the character that's sliding out of the window
            freq2[s2[i - n1] - 'a']--;
            
            // Check if the current window matches the frequency of s1
            if (freq1 == freq2) return true;
        }
        
        return false;
    }
};