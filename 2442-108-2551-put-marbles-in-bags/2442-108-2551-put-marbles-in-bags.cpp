class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0; // If k == 1, only one partition exists, so max - min = 0

        vector<long long> pairSums;
        
        // Compute pair sums for adjacent elements
        for (int i = 0; i < n - 1; i++) {
            pairSums.push_back(weights[i] + weights[i + 1]);
        }

        // Sort pairSums to get smallest and largest partition sums
        sort(pairSums.begin(), pairSums.end());

        long long minScore = 0, maxScore = 0;

        // Choose (k-1) smallest and largest partition sums
        for (int i = 0; i < k - 1; i++) {
            minScore += pairSums[i];                  // Smallest sums for min score
            maxScore += pairSums[n - 2 - i];          // Largest sums for max score
        }

        return maxScore - minScore;
    }
};