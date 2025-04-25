class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }

        dp[0].insert(0);  // Starting position with 0 jump

        for (int stone : stones) {
            for (int jump : dp[stone]) {
                for (int step = jump - 1; step <= jump + 1; ++step) {
                    if (step > 0 && dp.count(stone + step)) {
                        dp[stone + step].insert(step);
                    }
                }
            }
        }

        return !dp[stones.back()].empty(); // Can we reach the last stone?
    }
};