class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store {value, index_of_list, index_of_element_in_list}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int maxVal = INT_MIN;  // Keep track of the maximum value in the current range
        int rangeStart = 0, rangeEnd = INT_MAX;  // Initialize result range

        // Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], i, 0});  // {value, index_of_list, index_in_list}
            maxVal = max(maxVal, nums[i][0]);  // Track the maximum value
        }

        // Start processing the heap
        while (!minHeap.empty()) {
            auto minElement = minHeap.top();
            minHeap.pop();

            int minVal = minElement[0];  // Get the current minimum value
            int listIndex = minElement[1];  // Index of the list from which the minVal came
            int elemIndex = minElement[2];  // Index of the element in that list

            // Check if the current range is smaller than the previously found range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // Move to the next element in the list that minElement came from
            if (elemIndex + 1 < nums[listIndex].size()) {
                // Push the next element from this list into the heap
                int nextVal = nums[listIndex][elemIndex + 1];
                minHeap.push({nextVal, listIndex, elemIndex + 1});
                
                // Update the maxVal with the new element
                maxVal = max(maxVal, nextVal);
            } else {
                // If we have exhausted one of the lists, stop the process
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};