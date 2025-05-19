class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int sLen = s.size(), pLen = p.size();
        
        if (sLen < pLen) return res; // Can't form an anagram
        
        vector<int> sFreq(26, 0), pFreq(26, 0);
        
        // Build frequency map for p
        for (char c : p) {
            pFreq[c - 'a']++;
        }
        
        // First window
        for (int i = 0; i < pLen; ++i) {
            sFreq[s[i] - 'a']++;
        }
        
        if (sFreq == pFreq) res.push_back(0);
        
        // Slide the window
        for (int i = pLen; i < sLen; ++i) {
            sFreq[s[i] - 'a']++;                   // Add new char to window
            sFreq[s[i - pLen] - 'a']--;            // Remove old char from window
            
            if (sFreq == pFreq) res.push_back(i - pLen + 1);
        }
        
        return res;
    }
};
