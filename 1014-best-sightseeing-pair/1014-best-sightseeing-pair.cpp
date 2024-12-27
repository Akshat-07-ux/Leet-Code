class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;  // To store the maximum score
        int maxPrefix = values[0];  // To store the maximum `values[i] + i` encountered so far

        for (int j = 1; j < values.size(); ++j) {
            // Calculate the score for the current pair (i, j) with the maximum `values[i] + i` found so far
            maxScore = max(maxScore, maxPrefix + values[j] - j);

            // Update the maximum `values[i] + i` for future pairs
            maxPrefix = max(maxPrefix, values[j] + j);
        }

        return maxScore;
    }
};