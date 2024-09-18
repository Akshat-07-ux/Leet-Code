class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }

        // Custom sort function to decide order based on concatenated values
        sort(numStrs.begin(), numStrs.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // If the largest number is "0", then all numbers are "0"
        if (numStrs[0] == "0") {
            return "0";
        }

        // Concatenate the sorted strings
        string result;
        for (string &s : numStrs) {
            result += s;
        }

        return result;
    }
};
