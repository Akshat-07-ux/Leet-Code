class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0); // Prefix sum array
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq; // Deque to store indices
        int minLength = INT_MAX;

        // Iterate through the prefix sum array
        for (int i = 0; i <= n; ++i) {
            // Check if we have found a valid subarray with sum >= k
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            // Remove elements from the back of the deque if they are not useful
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);
        }

        return (minLength == INT_MAX) ? -1 : minLength;
    }
};