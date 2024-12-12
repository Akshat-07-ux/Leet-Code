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

    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxArea = max(maxArea, dfs(grid, visited, i, j));
                }
            }
        }

        return maxArea;
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int prev1 = 0, prev2 = 0;
        for (int num : nums) {
            int temp = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
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

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }

        visited[i][j] = true;
        int area = 1;

        // Check all 8 possible directions
        static int rowDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static int colDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int d = 0; d < 8; d++) {
            area += dfs(grid, visited, i + rowDir[d], j + colDir[d]);
        }

        return area;
    }
};