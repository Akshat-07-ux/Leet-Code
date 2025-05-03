class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotationTop = 0;
        int rotationBottom = 0;
        int n = tops.size();

        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;
            } else if (tops[i] != target) {
                rotationTop++;  // Need to rotate this to get target on top
            } else if (bottoms[i] != target) {
                rotationBottom++;  // Need to rotate to get target on bottom
            }
        }
        return min(rotationTop, rotationBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);  // Try top[0] as the candidate

        if (result != -1) return result;
        // If top[0] didn’t work, try bottom[0] only if it's different
        if (tops[0] != bottoms[0]) {
            return check(bottoms[0], tops, bottoms);
        }
        return -1;
    }
};