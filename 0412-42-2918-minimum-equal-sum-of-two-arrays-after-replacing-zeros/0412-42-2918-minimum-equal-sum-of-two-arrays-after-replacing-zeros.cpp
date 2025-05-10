class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        for (int num : nums1) {
            if (num == 0) zero1++;
            else sum1 += num;
        }

        for (int num : nums2) {
            if (num == 0) zero2++;
            else sum2 += num;
        }

        // Case 1: Both have zeros, we can adjust freely
        if (zero1 > 0 && zero2 > 0) {
            long long total1 = sum1 + zero1;
            long long total2 = sum2 + zero2;
            return max(total1, total2);
        }

        // Case 2: Only nums1 has zeros
        if (zero1 > 0) {
            long long minPossible = sum1 + zero1;
            if (minPossible > sum2) return -1;
            return sum2;
        }

        // Case 3: Only nums2 has zeros
        if (zero2 > 0) {
            long long minPossible = sum2 + zero2;
            if (minPossible > sum1) return -1;
            return sum1;
        }

        // Case 4: No zeros, check if already equal
        if (sum1 == sum2) return sum1;
        return -1;
    }
};