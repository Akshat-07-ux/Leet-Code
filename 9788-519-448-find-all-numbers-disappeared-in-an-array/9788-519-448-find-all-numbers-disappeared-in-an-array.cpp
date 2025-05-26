class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark the index corresponding to each number as visited
        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
                nums[index] = -nums[index];
        }

        vector<int> result;
        // The indices which are still positive are the missing numbers
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                result.push_back(i + 1);
        }

        return result;
    }
};