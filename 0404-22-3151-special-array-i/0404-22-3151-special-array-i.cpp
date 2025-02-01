class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            // If adjacent elements have the same parity, return false
            if ((nums[i] % 2) == (nums[i - 1] % 2)) 
                return false;
        }
        
        return true; // If all adjacent elements have different parity, return true
    }
};