class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;

        for (char digit : num) {
            // Pop from result if last digit is bigger and we still have k to remove
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        // If k > 0, remove from the end
        while (k-- > 0 && !result.empty()) {
            result.pop_back();
        }

        // Remove leading zeros
        int nonZeroIndex = 0;
        while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0') {
            nonZeroIndex++;
        }

        result = result.substr(nonZeroIndex);
        
        return result.empty() ? "0" : result;
    }
};