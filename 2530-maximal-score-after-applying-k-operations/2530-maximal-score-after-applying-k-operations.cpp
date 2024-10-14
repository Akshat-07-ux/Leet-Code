class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Max heap to store elements
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long score = 0;

        // Perform k operations
        for (int i = 0; i < k; ++i) {
            // Get the largest element
            int maxVal = maxHeap.top();
            maxHeap.pop();

            // Add the largest element to the score
            score += maxVal;

            // Replace it with ceil(maxVal / 3) and push it back to the heap
            maxHeap.push(ceil(maxVal / 3.0));
        }

        return score;
    }
};