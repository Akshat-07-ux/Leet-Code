class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int low = 0, high = nums[n - 1] - nums[0];
        int ans = high;

        auto canFormPairs = [&](int maxDiff) {
            int count = 0;
            for (int i = 0; i < n - 1; ) {
                if (nums[i + 1] - nums[i] <= maxDiff) {
                    count++;
                    i += 2; // skip the next index to avoid overlap
                } else {
                    i++;
                }
            }
            return count >= p;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFormPairs(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};