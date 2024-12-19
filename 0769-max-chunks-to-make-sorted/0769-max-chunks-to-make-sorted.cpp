class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxSeen = 0; // Tracks the maximum value encountered so far
        int chunks = 0;  // Counts the number of chunks

        for (int i = 0; i < arr.size(); i++) {
            maxSeen = max(maxSeen, arr[i]); // Update maxSeen
            if (maxSeen == i) { // If maxSeen matches the current index
                chunks++; // We can form a chunk
            }
        }

        return chunks; // Return the total number of chunks
    }
};