class Solution {
public:
    void dfs(vector<int>& nums, int index, int currentXor, int& total) {
        if (index == nums.size()) {
            total += currentXor;
            return;
        }
        
        // Include nums[index]
        dfs(nums, index + 1, currentXor ^ nums[index], total);
        
        // Exclude nums[index]
        dfs(nums, index + 1, currentXor, total);
    }

    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        dfs(nums, 0, 0, total);
        return total;
    }
};