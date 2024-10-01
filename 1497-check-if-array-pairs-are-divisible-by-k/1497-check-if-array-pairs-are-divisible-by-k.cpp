class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // Frequency map to store remainders
        vector<int> remainderCount(k, 0);

        // Calculate remainder frequencies
        for (int num : arr) {
            int rem = ((num % k) + k) % k;  // Handle negative numbers
            remainderCount[rem]++;
        }

        // Check conditions for forming pairs
        for (int i = 0; i < k; ++i) {
            // For remainder 0, there should be an even count
            if (i == 0) {
                if (remainderCount[i] % 2 != 0) return false;
            }
            // For other remainders, count[rem] should match count[k - rem]
            else {
                if (remainderCount[i] != remainderCount[k - i]) return false;
            }
        }

        return true;
    }
};