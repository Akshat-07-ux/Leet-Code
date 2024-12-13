class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        // If the array is not rotated
        if (arr[low] <= arr[high])
            return arr[low];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid element is the minimum
            if (mid > 0 && arr[mid] < arr[mid - 1])
                return arr[mid];

            // Check if the next element is the minimum
            if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1])
                return arr[mid + 1];

            // Adjust the search range
            if (arr[mid] >= arr[low]) {
                // Minimum is in the right part
                low = mid + 1;
            } else {
                // Minimum is in the left part
                high = mid - 1;
            }
        }

        return -1; // This line should never be reached for a valid rotated array
    }

    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        set<pair<int, int>> elements; // Store (value, index) pairs
        vector<bool> marked(n, false);

        for (int i = 0; i < n; ++i) {
            elements.insert({nums[i], i});
        }

        for (auto [value, index] : elements) {
            if (!marked[index]) {
                score += value;
                marked[index] = true;
                if (index > 0) marked[index - 1] = true;
                if (index < n - 1) marked[index + 1] = true;
            }
        }

        return score;
    }
};