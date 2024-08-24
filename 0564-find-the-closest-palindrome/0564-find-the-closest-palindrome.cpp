class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        long long num = stoll(n);

        // Candidate palindromes
        vector<long long> candidates;
        
        // Add edge case palindromes: 10^k - 1, 10^(k-1) + 1
        candidates.push_back(pow(10, len - 1) - 1);
        candidates.push_back(pow(10, len) + 1);
        
        // Get the prefix which will be used to generate middle-derived palindromes
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        // Generate possible palindromes by modifying the prefix
        for (long long i = -1; i <= 1; ++i) {
            string newPrefix = to_string(prefix + i);
            string candidate = newPrefix + string(newPrefix.rbegin() + (len % 2), newPrefix.rend());
            candidates.push_back(stoll(candidate));
        }

        // Remove the original number itself from the candidates
        long long closest = -1;
        for (long long candidate : candidates) {
            if (candidate != num) {
                if (closest == -1 || abs(candidate - num) < abs(closest - num) ||
                    (abs(candidate - num) == abs(closest - num) && candidate < closest)) {
                    closest = candidate;
                }
            }
        }

        return to_string(closest);
    }
};