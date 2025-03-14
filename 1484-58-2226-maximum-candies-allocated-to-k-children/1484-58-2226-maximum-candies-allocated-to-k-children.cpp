class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid; // Number of children that can get 'mid' candies from this pile
            if (count >= k) return true; // No need to check further if we already have enough
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        if (accumulate(candies.begin(), candies.end(), 0LL) < k) return 0; // Not enough candies

        int left = 1, right = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAllocate(candies, k, mid)) {
                ans = mid;  // Possible answer, but try for a larger one
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};