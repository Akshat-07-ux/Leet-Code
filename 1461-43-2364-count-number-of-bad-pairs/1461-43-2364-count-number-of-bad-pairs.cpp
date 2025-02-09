class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2; // Total number of pairs

        unordered_map<int, long long> freq;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i; // Transforming condition: j - i == nums[j] - nums[i]
            goodPairs += freq[key]; // Count valid (good) pairs
            freq[key]++; // Store frequency of transformation
        }

        return totalPairs - goodPairs; // Bad pairs = Total pairs - Good pairs
    }
};