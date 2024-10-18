class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        int count = 0;
        int n = nums.size();
        
        // Find the maximum OR we can achieve by OR-ing all elements together
        for (int num : nums) {
            maxOR |= num;
        }
        
        // Iterate through all subsets using bit manipulation
        for (int subset = 1; subset < (1 << n); ++subset) {
            int currentOR = 0;
            
            // For each subset, calculate the OR of its elements
            for (int i = 0; i < n; ++i) {
                if (subset & (1 << i)) {
                    currentOR |= nums[i];
                }
            }
            
            // If this subset's OR matches the maximum OR, increment the count
            if (currentOR == maxOR) {
                count++;
            }
        }
        
        return count;
    }
};