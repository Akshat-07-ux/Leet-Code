class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by their end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> maxValue(n, 0); // Stores the maximum value of a single event up to each index
        maxValue[0] = events[0][2];

        // Precompute the maximum single event value up to each index
        for (int i = 1; i < n; ++i) {
            maxValue[i] = max(maxValue[i - 1], events[i][2]);
        }

        int result = 0;

        // Iterate over each event to find the best combination
        for (int i = 0; i < n; ++i) {
            // Include the current event
            int currentValue = events[i][2];

            // Use binary search to find the latest non-overlapping event
            int left = 0, right = i - 1, bestIndex = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][1] < events[i][0]) {
                    bestIndex = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            // Add the value of the best non-overlapping event, if it exists
            if (bestIndex != -1) {
                currentValue += maxValue[bestIndex];
            }

            // Update the result with the maximum sum
            result = max(result, currentValue);
        }

        return result;
    }
};