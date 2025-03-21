class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;

        // Step 1: Sort envelopes by width (ascending), and by height (descending if widths are equal)
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        // Step 2: Apply Longest Increasing Subsequence (LIS) on heights
        vector<int> lis;
        for (auto& env : envelopes) {
            int height = env[1];
            auto it = lower_bound(lis.begin(), lis.end(), height);
            if (it == lis.end()) {
                lis.push_back(height);
            } else {
                *it = height;
            }
        }

        return lis.size();
    }
};