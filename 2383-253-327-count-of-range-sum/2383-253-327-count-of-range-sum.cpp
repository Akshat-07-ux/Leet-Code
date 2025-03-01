class Solution {
public:
    int mergeCount(vector<long>& prefix, int left, int mid, int right, int lower, int upper) {
        int count = 0, j = mid, k = mid, t = mid;
        vector<long> temp(right - left);
        int idx = 0;

        for (int i = left; i < mid; i++) {
            while (j < right && prefix[j] - prefix[i] < lower) j++;
            while (k < right && prefix[k] - prefix[i] <= upper) k++;
            count += (k - j);
        }

        merge(prefix.begin() + left, prefix.begin() + mid, prefix.begin() + mid, prefix.begin() + right, temp.begin());
        move(temp.begin(), temp.begin() + (right - left), prefix.begin() + left);

        return count;
    }

    int mergeSort(vector<long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSort(prefix, left, mid, lower, upper) + mergeSort(prefix, mid, right, lower, upper);
        count += mergeCount(prefix, left, mid, right, lower, upper);
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n + 1, lower, upper);
    }
};