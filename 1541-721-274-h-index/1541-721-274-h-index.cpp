class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Sort the citations in ascending order
        sort(citations.begin(), citations.end());
        
        int n = citations.size();
        int hIndex = 0;

        // Traverse the sorted array
        for (int i = 0; i < n; i++) {
            // The number of papers with at least `citations[i]` citations
            int h = n - i;
            if (citations[i] >= h) {
                hIndex = h;
                break;
            }
        }

        return hIndex;
    }
};