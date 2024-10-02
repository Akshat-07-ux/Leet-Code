class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a copy of the original array and sort it
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Use an unordered_map to store the rank for each unique element
        unordered_map<int, int> rankMap;
        int rank = 1;

        // Assign ranks to each unique element
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }

        // Replace elements in the original array with their rank
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }

        return arr;
    }
};