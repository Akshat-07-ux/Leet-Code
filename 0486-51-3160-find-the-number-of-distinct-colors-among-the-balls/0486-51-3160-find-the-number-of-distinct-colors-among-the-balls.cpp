class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;  // Maps a ball to its current color
        unordered_set<int> distinctColors;  // Keeps track of distinct colors
        vector<int> result;
        
        for (auto& query : queries) {
            int ball = query[0], color = query[1];
            
            // If the ball already had a color, remove the old color if necessary
            if (ballColor.count(ball)) {
                int oldColor = ballColor[ball];
                if (oldColor != color) {
                    // Remove the old color if no other ball is using it
                    if (count_if(ballColor.begin(), ballColor.end(), [&](const auto& p) { return p.second == oldColor; }) == 1) {
                        distinctColors.erase(oldColor);
                    }
                }
            }
            
            // Assign the new color
            ballColor[ball] = color;
            distinctColors.insert(color);
            
            // Store the number of distinct colors
            result.push_back(distinctColors.size());
        }
        
        return result;
    }
};
