class Solution {
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        // Convert wordDict to a set for quick lookup
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        // Memoization map to store results of substrings
        std::unordered_map<std::string, std::vector<std::string>> memo;
        return dfs(s, dict, memo);
    }
    
private:
    std::vector<std::string> dfs(const std::string& s, std::unordered_set<std::string>& dict, std::unordered_map<std::string, std::vector<std::string>>& memo) {
        // If the substring result is already computed, return it
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        std::vector<std::string> result;
        
        // Check if the whole string is a word in the dictionary
        if (dict.find(s) != dict.end()) {
            result.push_back(s);
        }
        
        // Try every possible partition
        for (int i = 1; i < s.length(); ++i) {
            std::string left = s.substr(0, i);
            std::string right = s.substr(i);
            
            // Only proceed if the left part is a word in the dictionary
            if (dict.find(left) != dict.end()) {
                // Recursive DFS on the right part
                std::vector<std::string> rightResult = dfs(right, dict, memo);
                
                // Combine the left part with each sentence in the rightResult
                for (const std::string& sentence : rightResult) {
                    result.push_back(left + " " + sentence);
                }
            }
        }
        
        // Store the result for the current substring in memo
        memo[s] = result;
        return result;
    }
};