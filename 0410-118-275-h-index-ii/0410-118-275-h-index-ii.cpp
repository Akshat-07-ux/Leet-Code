class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1, mid;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            int h = n - mid;  // h-index candidate
            
            if (citations[mid] == h) {
                return h;  // Found exact match
            } else if (citations[mid] < h) {
                left = mid + 1;  // Move right
            } else {
                right = mid - 1; // Move left
            }
        }
        
        return n - left;
    }
};