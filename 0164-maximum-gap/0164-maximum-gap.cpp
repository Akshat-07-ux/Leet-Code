class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        
        // If there are fewer than 2 elements, return 0
        if (n < 2) return 0;
        
        // Find the minimum and maximum values in the array
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // Calculate the minimum possible gap using the pigeonhole principle
        int gap = (maxVal - minVal) / (n - 1) + 1;
        
        // Create the buckets
        vector<pair<int, int>> buckets(n, {INT_MAX, INT_MIN});
        
        // Place each number in the appropriate bucket
        for (int num : nums) {
            if (num == minVal || num == maxVal) continue; // Ignore min and max
            int index = (num - minVal) / gap;
            buckets[index].first = min(buckets[index].first, num); // Min value in the bucket
            buckets[index].second = max(buckets[index].second, num); // Max value in the bucket
        }
        
        // Now find the maximum gap
        int prevMax = minVal;
        int maxGap = 0;
        
        for (auto& bucket : buckets) {
            if (bucket.first == INT_MAX) continue; // Empty bucket
            maxGap = max(maxGap, bucket.first - prevMax);
            prevMax = bucket.second;
        }
        
        // Final check for the last bucket's max value
        maxGap = max(maxGap, maxVal - prevMax);
        
        return maxGap;
    }
};