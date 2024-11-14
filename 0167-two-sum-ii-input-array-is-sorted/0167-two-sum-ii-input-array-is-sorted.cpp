class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        // Use two-pointer technique
        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                // Indices are 1-indexed, so return left + 1 and right + 1
                return {left + 1, right + 1};
            } else if (sum < target) {
                // Move the left pointer to the right to increase the sum
                left++;
            } else {
                // Move the right pointer to the left to decrease the sum
                right--;
            }
        }

        // Since there is always exactly one solution, this line will never be reached
        return {};
    }
};