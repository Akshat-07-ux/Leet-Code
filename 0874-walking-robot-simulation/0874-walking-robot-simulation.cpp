class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, directionIndex = 0;
        int maxDistanceSquared = 0;

        // Convert obstacles to a set of string for quick lookup
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        for (int command : commands) {
            if (command == -2) { // Turn left
                directionIndex = (directionIndex + 3) % 4;
            } else if (command == -1) { // Turn right
                directionIndex = (directionIndex + 1) % 4;
            } else {
                // Move forward
                for (int i = 0; i < command; ++i) {
                    int nextX = x + directions[directionIndex].first;
                    int nextY = y + directions[directionIndex].second;
                    if (obstacleSet.find(to_string(nextX) + "," + to_string(nextY)) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
                    } else {
                        break; // Hit an obstacle, stop moving
                    }
                }
            }
        }

        return maxDistanceSquared;
    }
};