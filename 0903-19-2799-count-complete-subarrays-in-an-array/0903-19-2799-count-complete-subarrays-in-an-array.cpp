class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique; // To get total distinct elements
        for (int num : nums) {
            unique.insert(num);
        }
        int totalDistinct = unique.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            int distinct = 0;
            for (int j = i; j < n; j++) {
                if (++freq[nums[j]] == 1) {
                    distinct++;
                }
                if (distinct == totalDistinct) {
                    count++;
                }
            }
        }

        return count;
    }
};