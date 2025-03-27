class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int dominant = nums[0], max_count = 0;

        // Determine the dominant element
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > max_count) {
                max_count = freq[num];
                dominant = num;
            }
        }

        int left_count = 0, right_count = max_count;

        // Traverse the array to find the minimum valid split index
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == dominant) {
                left_count++;
                right_count--;
            }
            if (left_count * 2 > i + 1 && right_count * 2 > n - i - 1) {
                return i;
            }
        }
        return -1; // No valid split found
    }
};