class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;
        
        // Generate all the numbers in lexicographical order
        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            
            // Try to go deeper in the lexicographical tree
            if (current * 10 <= n) {
                current *= 10;
            } else {
                // If we cannot multiply by 10, we try to move to the next number
                if (current >= n) {
                    current /= 10;
                }
                current++;
                
                // Skip numbers like 19 -> 20 (jump over numbers ending in 9)
                while (current % 10 == 0) {
                    current /= 10;
                }
            }
        }
        
        return result;
    }
};