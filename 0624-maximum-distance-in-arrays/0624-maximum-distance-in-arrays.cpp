class Solution {
public:
    int maxDistance(std::vector<std::vector<int>>& arrays) {
        int minVal = arrays[0].front();  // Minimum element from the first array
        int maxVal = arrays[0].back();   // Maximum element from the first array
        int maxDist = 0;
        
        // Iterate through the rest of the arrays
        for (int i = 1; i < arrays.size(); ++i) {
            // Calculate possible maximum distances
            maxDist = std::max(maxDist, std::abs(arrays[i].back() - minVal));
            maxDist = std::max(maxDist, std::abs(maxVal - arrays[i].front()));
            
            // Update the global min and max
            minVal = std::min(minVal, arrays[i].front());
            maxVal = std::max(maxVal, arrays[i].back());
        }
        
        return maxDist;
    }
};