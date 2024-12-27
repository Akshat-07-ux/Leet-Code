class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // If there's only one house, rob it.
        if (n == 2) return max(nums[0], nums[1]); // If there are two houses, rob the one with more money.

        // Helper function to calculate the maximum amount using standard House Robber logic
        auto robLinear = [](vector<int>& houses) -> int {
            int prev = 0, curr = 0;
            for (int money : houses) {
                int temp = curr;
                curr = max(curr, prev + money); // Max of robbing this house or skipping it
                prev = temp;
            }
            return curr;
        };

        // Rob houses excluding the first one
        vector<int> excludeFirst(nums.begin() + 1, nums.end());
        // Rob houses excluding the last one
        vector<int> excludeLast(nums.begin(), nums.end() - 1);

        return max(robLinear(excludeFirst), robLinear(excludeLast));
    }
};