class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        
        // Convert all time points to minutes
        for (const string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }
        
        // Sort the minutes
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        
        // Compare adjacent time points
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }
        
        // Compare the first and last time points (circular comparison)
        int circularDiff = (minutes[0] + 1440) - minutes.back();
        minDiff = min(minDiff, circularDiff);
        
        return minDiff;
    }
};