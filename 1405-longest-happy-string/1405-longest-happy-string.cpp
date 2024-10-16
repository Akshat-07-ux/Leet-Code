class Solution {
public:
    std::string longestDiverseString(int a, int b, int c) {
        // This vector will hold the pairs of character counts and corresponding characters
        std::vector<std::pair<int, char>> freq = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        std::string result = "";
        
        while (true) {
            // Sort in descending order to always try to use the character with the highest remaining count
            std::sort(freq.rbegin(), freq.rend());
            
            bool added = false;
            
            // Try to add the character with the highest frequency
            for (auto &p : freq) {
                int count = p.first;
                char ch = p.second;
                
                // Check if we can add this character without violating the happy condition
                int len = result.size();
                if (count > 0 && (len < 2 || result[len-1] != ch || result[len-2] != ch)) {
                    // Add the character to the result
                    result += ch;
                    p.first--;  // Decrease the count
                    added = true;
                    break;  // Break the loop and attempt adding again in the next iteration
                }
            }
            
            // If no character could be added, break out of the loop
            if (!added) {
                break;
            }
        }
        
        return result;
    }
};