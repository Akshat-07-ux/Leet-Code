class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> streak;  // streak[num] stores the longest streak ending at num
        int maxLength = -1;

        for (int num : nums) {
            int root = sqrt(num);
            if (root * root == num && streak.count(root)) {
                streak[num] = streak[root] + 1;
            } else {
                streak[num] = 1;
            }
            if (streak[num] >= 2) {
                maxLength = max(maxLength, streak[num]);
            }
        }

        return maxLength;
    }
};