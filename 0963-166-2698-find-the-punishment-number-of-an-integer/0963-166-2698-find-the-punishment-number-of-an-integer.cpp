class Solution {
public:
    // Helper function to check if a number can be partitioned
    bool canPartition(string sq, int index, int target) {
        if (index == sq.size()) return target == 0;
        
        int num = 0;
        for (int i = index; i < sq.size(); i++) {
            num = num * 10 + (sq[i] - '0');
            if (num > target) break;
            if (canPartition(sq, i + 1, target - num)) return true;
        }
        return false;
    }

    // Function to calculate the punishment number
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canPartition(to_string(square), 0, i)) {
                sum += square;
            }
        }
        return sum;
    }
};