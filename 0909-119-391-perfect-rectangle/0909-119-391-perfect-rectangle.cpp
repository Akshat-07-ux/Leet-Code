class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        using ll = long long;
        unordered_set<string> corners;
        ll totalArea = 0;

        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        for (auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1];
            int x2 = rect[2], y2 = rect[3];

            // Update bounding box
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            // Area of current rectangle
            totalArea += (ll)(x2 - x1) * (y2 - y1);

            // Mark corners
            vector<string> points = {
                to_string(x1) + " " + to_string(y1),
                to_string(x1) + " " + to_string(y2),
                to_string(x2) + " " + to_string(y1),
                to_string(x2) + " " + to_string(y2),
            };

            for (const string& pt : points) {
                if (corners.count(pt))
                    corners.erase(pt);
                else
                    corners.insert(pt);
            }
        }

        // Only 4 corners should be left
        if (corners.size() != 4) return false;

        // Must match the bounding rectangle corners
        vector<string> expectedCorners = {
            to_string(minX) + " " + to_string(minY),
            to_string(minX) + " " + to_string(maxY),
            to_string(maxX) + " " + to_string(minY),
            to_string(maxX) + " " + to_string(maxY),
        };

        for (const string& pt : expectedCorners) {
            if (!corners.count(pt)) return false;
        }

        // Area check
        ll bigArea = (ll)(maxX - minX) * (maxY - minY);
        return totalArea == bigArea;
    }
};
