class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int mid = (n - 1) / 2;  // Median index for odd count
        int high = n - 1;

        // Virtual indexing technique for correct placement
        for (int i = 0; i < n; i++) {
            nums[i] = (i % 2 == 0) ? sorted[mid--] : sorted[high--];
        }
    }
};