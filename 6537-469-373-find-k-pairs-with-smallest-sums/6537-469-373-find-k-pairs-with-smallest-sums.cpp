class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Min-heap: Stores (sum, index in nums1, index in nums2)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        // Push the first k pairs (nums1[i], nums2[0]) into heap
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        // Extract k smallest pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});

            // Push the next element in nums2 for the same nums1[i]
            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};