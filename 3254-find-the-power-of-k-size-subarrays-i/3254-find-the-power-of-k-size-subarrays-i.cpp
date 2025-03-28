class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        
        for (int i = 0; i <= n - k; i++) {
            bool isConsecutive = true;
            int maxElement = nums[i];
            
            // Check if the current subarray is sorted and has consecutive elements
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    isConsecutive = false;
                    break;
                }
                maxElement = max(maxElement, nums[j]);
            }
            
            // If the subarray is consecutive and sorted, add the max element to result
            if (isConsecutive) {
                result.push_back(maxElement);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};