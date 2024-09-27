class MyCalendarTwo {
private:
    map<int, int> events; // Stores the start and end times with counts.

public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // Mark the start and end of the event
        events[start]++;
        events[end]--;
        
        int activeBookings = 0;
        // Traverse through the events to check for triple booking
        for (auto& event : events) {
            activeBookings += event.second;
            if (activeBookings >= 3) {
                // If triple booking occurs, rollback the changes and return false
                events[start]--;
                events[end]++;
                return false;
            }
        }
        // If no triple booking, return true
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */