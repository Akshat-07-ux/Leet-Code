class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;  // Any two points are always on the same line

        int maxPointsOnLine = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeMap;  // Map to store slope frequencies
            int duplicate = 1;  // Count the point itself
            int currentMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;  // Handle duplicate points
                } else {
                    int gcd = __gcd(dx, dy);  // Get the greatest common divisor to reduce slope
                    dx /= gcd;
                    dy /= gcd;

                    // Create a unique representation for each slope
                    string slope = to_string(dy) + "/" + to_string(dx);
                    slopeMap[slope]++;
                    currentMax = max(currentMax, slopeMap[slope]);
                }
            }

            maxPointsOnLine = max(maxPointsOnLine, currentMax + duplicate);
        }

        return maxPointsOnLine;
    }
};