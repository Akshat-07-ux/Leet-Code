class Solution {
public:
    // Helper function to check if a given x is feasible
    bool canDistribute(int n, vector<int>& quantities, int x) {
        int requiredStores = 0;
        for (int quantity : quantities) {
            // Calculate the minimum number of stores needed for this product type
            requiredStores += (quantity + x - 1) / x;
            if (requiredStores > n) {
                return false; // Not feasible if we exceed the number of stores
            }
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(n, quantities, mid)) {
                result = mid;
                right = mid - 1; // Try to find a smaller maximum value
            } else {
                left = mid + 1; // Increase mid value
            }
        }

        return result;
    }
};