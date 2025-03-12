class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        // Finding the first index of a positive number
        int posIndex = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        // Finding the first index of zero (to determine negatives)
        int negIndex = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        int posCount = n - posIndex; // Count of positive numbers
        int negCount = negIndex;     // Count of negative numbers
        
        return max(posCount, negCount);
    }
};