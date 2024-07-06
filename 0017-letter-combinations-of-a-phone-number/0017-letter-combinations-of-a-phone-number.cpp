class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        backtrack(digits, 0, current, result, digitToLetters);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current, 
                   vector<string>& result, const unordered_map<char, string>& digitToLetters) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        for (char letter : digitToLetters.at(digits[index])) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result, digitToLetters);
            current.pop_back();
        }
    }
};