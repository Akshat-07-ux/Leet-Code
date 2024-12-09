class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parityDiff(n - 1, 0);

        // Step 1: Precompute parity differences
        for (int i = 0; i < n - 1; ++i) {
            parityDiff[i] = (nums[i] % 2) != (nums[i + 1] % 2);
        }

        // Step 2: Prefix sum for parityDiff
        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + parityDiff[i - 1];
        }

        vector<bool> result;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            if (r == l) {
                // A single element is always special
                result.push_back(true);
            } else {
                int diffCount = prefixSum[r] - prefixSum[l];
                result.push_back(diffCount == (r - l));
            }
        }

        return result;
    }
};