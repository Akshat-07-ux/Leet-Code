class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int first = findFirstOccurrence(arr, target);
        if (first == -1) {
            // Target is not present in the array
            return 0;
        }
        int last = findLastOccurrence(arr, target);
        return last - first + 1;
    }

    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        while (k-- > 0 && !maxHeap.empty()) {
            int maxGifts = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(floor(sqrt(maxGifts)));
        }

        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }

        return totalGifts;
    }

private:
    int findFirstOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                high = mid - 1; // Search on the left side
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    int findLastOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                low = mid + 1; // Search on the right side
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};