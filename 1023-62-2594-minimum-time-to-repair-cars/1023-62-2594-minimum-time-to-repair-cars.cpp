class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, int cars, long long mid) {
        long long totalCars = 0;
        for (int r : ranks) {
            totalCars += sqrt(mid / r); // Cars that this mechanic can repair
            if (totalCars >= cars) return true; // Early exit if possible
        }
        return totalCars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long) *min_element(ranks.begin(), ranks.end()) * (long long) cars * cars;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                right = mid - 1; // Try for lesser time
            } else {
                left = mid + 1; // Increase time
            }
        }
        return ans;
    }
};