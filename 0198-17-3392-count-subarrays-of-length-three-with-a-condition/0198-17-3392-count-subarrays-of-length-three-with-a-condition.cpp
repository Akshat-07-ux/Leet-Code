class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i <= n - 3; ++i) {
            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];
            
            // Check if second is even first, to avoid weird fractions
            if (second % 2 == 0) {
                if (first + third == second / 2) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
