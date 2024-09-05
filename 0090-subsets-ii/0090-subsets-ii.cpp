class Solution {
public:
    // Function to generate all unique subsets
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int start) {
        // Add the current subset to the result
        result.push_back(current);

        // Iterate through the remaining elements
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates to avoid duplicate subsets
            if (i > start && nums[i] == nums[i - 1]) continue;

            // Include the current element in the subset
            current.push_back(nums[i]);

            // Recur to generate further subsets including this element
            backtrack(nums, result, current, i + 1);

            // Backtrack: remove the last element to explore the next possibility
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the input array to handle duplicates easily
        sort(nums.begin(), nums.end());

        // Result vector to store all unique subsets
        vector<vector<int>> result;

        // Temporary vector to store the current subset
        vector<int> current;

        // Start the backtracking process from index 0
        backtrack(nums, result, current, 0);

        return result;
    }
};
