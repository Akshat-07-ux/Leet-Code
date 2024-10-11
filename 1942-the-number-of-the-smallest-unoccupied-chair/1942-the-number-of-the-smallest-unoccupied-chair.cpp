class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        int n = times.size();

        // Add index of each friend in the times vector
        std::vector<std::vector<int>> events;
        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], times[i][1], i}); // {arrival, leaving, index}
        }

        // Sort the events by arrival time
        std::sort(events.begin(), events.end());

        // Min-heap to store the available chair numbers
        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        for (int i = 0; i < n; i++) {
            availableChairs.push(i);
        }

        // Min-heap to store friends that are currently sitting, sorted by leaving time
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> occupiedChairs;

        for (const auto& event : events) {
            int arrival = event[0];
            int leaving = event[1];
            int friendIndex = event[2];

            // Free up chairs that become available before or at the current friend's arrival time
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrival) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            // Assign the smallest available chair to the current friend
            int chair = availableChairs.top();
            availableChairs.pop();

            // If this is the target friend, return the chair number
            if (friendIndex == targetFriend) {
                return chair;
            }

            // Add the friend and their chair to the occupied chairs heap
            occupiedChairs.push({leaving, chair});
        }

        return -1; // This shouldn't happen since the target friend is guaranteed to be present
    }
};