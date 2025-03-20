class SummaryRanges {
private:
    set<int> nums;

public:
    SummaryRanges() {}

    void addNum(int value) {
        nums.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        if (nums.empty()) return result;

        auto it = nums.begin();
        int start = *it, end = *it;

        for (++it; it != nums.end(); ++it) {
            if (*it == end + 1) {
                end = *it; // Extend the interval
            } else {
                result.push_back({start, end});
                start = end = *it; // Start new interval
            }
        }
        result.push_back({start, end}); // Add last interval

        return result;
    }
};


/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */