class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;
        for(int c : chalk) {
            totalChalk += c;
        }
        
        k %= totalChalk;  // Reducing k to the equivalent smaller value after full rounds
        
        for(int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        return -1; // This line should never be reached
    }
};