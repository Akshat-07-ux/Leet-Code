class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Step 1: Count frequencies
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Create a custom comparator
        auto comparator = [&freqMap](int a, int b) {
            if (freqMap[a] != freqMap[b]) {
                return freqMap[a] < freqMap[b]; // Sort by increasing frequency
            }
            return a > b; // If frequencies are equal, sort by decreasing value
        };
        
        // Step 3: Sort the array using the custom comparator
        sort(nums.begin(), nums.end(), comparator);
        
        return nums;
    }
};