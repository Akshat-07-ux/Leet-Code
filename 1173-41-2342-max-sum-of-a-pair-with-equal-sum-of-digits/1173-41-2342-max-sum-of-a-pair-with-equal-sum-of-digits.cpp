class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; // Stores max value for each digit sum
        int maxSum = -1;

        for (int num : nums) {
            int sumOfDigits = getDigitSum(num);

            // If this digit sum has been seen before, check the sum of the two max values
            if (digitSumMap.find(sumOfDigits) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[sumOfDigits] + num);
            }

            // Update the max value for this sum of digits
            digitSumMap[sumOfDigits] = max(digitSumMap[sumOfDigits], num);
        }

        return maxSum;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10; // Extract last digit and add to sum
            num /= 10;       // Remove last digit
        }
        return sum;
    }
};