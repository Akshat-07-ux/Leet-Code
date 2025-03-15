class Solution {
public:
    bool canRob(vector<int>& nums, int k, int maxCap) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= maxCap) {
                count++;
                i++; // Skip the adjacent house
            }
            if (count >= k) return true;
        }
        
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canRob(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
