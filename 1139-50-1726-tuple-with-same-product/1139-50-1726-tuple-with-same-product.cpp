class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int count = 0;

        // Generate all possible product pairs
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Count the valid tuples
        for (auto& pair : productCount) {
            int freq = pair.second;
            if (freq > 1) {
                count += (freq * (freq - 1)) / 2 * 8;
            }
        }

        return count;
    }
};