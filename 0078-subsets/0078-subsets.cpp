class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int index) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Iterate through the array starting from the current index
        for (int i = index; i < nums.size(); ++i) {
            // Include nums[i] in the current subset
            current.push_back(nums[i]);
            
            // Recurse with the next index
            backtrack(nums, result, current, i + 1);
            
            // Backtrack: remove nums[i] from the current subset
            current.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, result, current, 0);
        return result;
    }
};