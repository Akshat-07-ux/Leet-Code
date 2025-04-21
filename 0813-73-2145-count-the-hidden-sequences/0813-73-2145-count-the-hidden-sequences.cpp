class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minSum = 0, maxSum = 0, sum = 0;

        for (int diff : differences) {
            sum += diff;
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
        }

        long long minStart = lower - minSum;
        long long maxStart = upper - maxSum;

        long long count = max(0LL, maxStart - minStart + 1);

        return (int)count;
    }
};