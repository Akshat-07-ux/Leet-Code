class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Map to store the changes in active intervals
        map<int, int> events;
        
        // Add start and end+1 events for each interval
        for (const auto& interval : intervals) {
            events[interval[0]]++;        // Start of interval
            events[interval[1] + 1]--;    // End of interval (non-inclusive)
        }
        
        int maxGroups = 0;
        int activeGroups = 0;
        
        // Traverse the event map in sorted order of time points
        for (const auto& event : events) {
            activeGroups += event.second; // Update the number of active groups
            maxGroups = max(maxGroups, activeGroups); // Track the maximum number of groups needed
        }
        
        return maxGroups;
    }
};