class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> secretCount, guessCount;

        // First pass: Count bulls and store non-bull characters in maps
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++; // Bull: Correct digit in the correct position
            } else {
                secretCount[secret[i]]++; // Track remaining digits in secret
                guessCount[guess[i]]++;   // Track remaining digits in guess
            }
        }

        // Second pass: Count cows
        for (auto &entry : guessCount) {
            char digit = entry.first;
            if (secretCount.find(digit) != secretCount.end()) {
                cows += min(secretCount[digit], guessCount[digit]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};