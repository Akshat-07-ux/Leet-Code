class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> countMap;
        int result = 0;

        for (auto& d : dominoes) {
            int a = d[0];
            int b = d[1];
            // Normalize using the smaller first and encoding to a single int: a*10 + b
            int key = min(a, b) * 10 + max(a, b);
            result += countMap[key];
            countMap[key]++;
        }

        return result;
    }
};