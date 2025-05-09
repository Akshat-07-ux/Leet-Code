class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        vector<int> digit(10, 0);

        // Unique identifiers
        digit[0] = count['z' - 'a'];
        digit[2] = count['w' - 'a'];
        digit[4] = count['u' - 'a'];
        digit[6] = count['x' - 'a'];
        digit[8] = count['g' - 'a'];

        // Digits with shared letters
        digit[3] = count['h' - 'a'] - digit[8];                // "three" - "eight"
        digit[5] = count['f' - 'a'] - digit[4];                // "five" - "four"
        digit[7] = count['s' - 'a'] - digit[6];                // "seven" - "six"
        digit[1] = count['o' - 'a'] - digit[0] - digit[2] - digit[4];
        digit[9] = count['i' - 'a'] - digit[5] - digit[6] - digit[8];

        string result;
        for (int i = 0; i <= 9; ++i) {
            result += string(digit[i], '0' + i);
        }

        return result;
    }
};