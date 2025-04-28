class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            
            // Shrink the window while the score is too big
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }
            
            // All subarrays ending at 'right' and starting from [left, right] are valid
            ans += (right - left + 1);
        }
        
        return ans;
    }
};