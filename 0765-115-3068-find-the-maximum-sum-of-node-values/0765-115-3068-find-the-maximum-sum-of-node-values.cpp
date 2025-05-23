class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long baseSum = 0;
        vector<int> gains;

        for (int num : nums) {
            int toggled = num ^ k;
            baseSum += num;
            gains.push_back(toggled - num);
        }

        sort(gains.rbegin(), gains.rend()); // sort descending

        long long totalGain = 0;
        int count = 0;

        for (int gain : gains) {
            if (gain > 0) {
                totalGain += gain;
                count++;
            }
        }

        // If odd number of gains selected, make it even
        if (count % 2 != 0) {
            int minLoss = INT_MAX;
            for (int gain : gains) {
                minLoss = min(minLoss, abs(gain));
            }
            totalGain -= minLoss;
        }

        return baseSum + totalGain;
    }
};