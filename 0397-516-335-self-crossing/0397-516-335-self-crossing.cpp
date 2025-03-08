class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if (n < 4) return false;  // Minimum steps required to cross is 4
        
        for (int i = 3; i < n; i++) {
            // Case 1: Current line crosses the line 3 steps back
            if (distance[i] >= distance[i-2] && distance[i-1] <= distance[i-3]) {
                return true;
            }

            // Case 2: Current line crosses the line 4 steps back (tight inward spiral)
            if (i >= 4 && distance[i-1] == distance[i-3] && distance[i] + distance[i-4] >= distance[i-2]) {
                return true;
            }

            // Case 3: Current line crosses the line 6 steps back (expansion then contraction)
            if (i >= 5 && distance[i-2] >= distance[i-4] &&
                distance[i] + distance[i-4] >= distance[i-2] &&
                distance[i-1] <= distance[i-3] &&
                distance[i-1] + distance[i-5] >= distance[i-3]) {
                return true;
            }
        }

        return false;
    }
};