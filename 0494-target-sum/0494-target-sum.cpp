class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo; // Define memo as a variable
        return countWays(nums, 0, target, memo);
    }

private:
    int countWays(vector<int>& nums, int index, int target, unordered_map<string, int>& memo) {
        // Base case: if we've processed all numbers
        if (index == nums.size()) {
            return (target == 0) ? 1 : 0;
        }

        // Create a unique key for the current state
        string key = to_string(index) + "," + to_string(target);

        // Check if the result for this state is already computed
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Recursive calls: consider adding and subtracting the current number
        int add = countWays(nums, index + 1, target - nums[index], memo);
        int subtract = countWays(nums, index + 1, target + nums[index], memo);

        // Store the result in the memo table and return it
        memo[key] = add + subtract;
        return memo[key];
    }
};