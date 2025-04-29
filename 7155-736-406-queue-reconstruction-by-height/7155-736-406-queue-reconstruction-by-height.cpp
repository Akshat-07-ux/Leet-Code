class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort by descending height and ascending k-value
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<vector<int>> result;

        // Insert each person at the index equal to their k-value
        for (const auto& person : people) {
            result.insert(result.begin() + person[1], person);
        }

        return result;
    }
};