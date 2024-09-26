class MyCalendar {
public:
    // Vector to store booked events as pairs of start and end times
    vector<pair<int, int>> bookings;

    // Constructor
    MyCalendar() { }

    // Function to check if a new event can be booked
    bool book(int start, int end) {
        // Iterate over all existing bookings
        for (const auto& booking : bookings) {
            // Check if the new event overlaps with an existing event
            if (max(booking.first, start) < min(booking.second, end)) {
                // If there is an overlap, return false
                return false;
            }
        }
        // If no overlap is found, add the new event to bookings
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */