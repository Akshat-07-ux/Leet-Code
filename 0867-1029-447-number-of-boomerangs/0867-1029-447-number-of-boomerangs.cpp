class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int total = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> distCount;
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distSq = dx * dx + dy * dy; // squared distance
                distCount[distSq]++;
            }
            for (auto& [dist, count] : distCount) {
                if (count >= 2) {
                    total += count * (count - 1);
                }
            }
        }
        return total;
    }
};