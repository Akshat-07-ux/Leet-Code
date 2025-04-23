class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> digitSumGroups;
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            digitSumGroups[sum]++;
            maxSize = max(maxSize, digitSumGroups[sum]);
        }

        int count = 0;
        for (auto& [key, value] : digitSumGroups) {
            if (value == maxSize) {
                count++;
            }
        }

        return count;
    }
};