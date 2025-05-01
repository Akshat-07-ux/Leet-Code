class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min((int)tasks.size(), (int)workers.size());
        int result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }

    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.end() - k, workers.end());

        int usedPills = 0;

        for (int i = k - 1; i >= 0; --i) {
            int task = tasks[i];

            // Try to find a worker who can do the task without a pill
            auto it = prev(availableWorkers.end());
            if (*it >= task) {
                availableWorkers.erase(it);
            } else {
                // Try to find a worker who can do the task with a pill
                auto it2 = availableWorkers.lower_bound(task - strength);
                if (it2 == availableWorkers.end()) return false;
                availableWorkers.erase(it2);
                usedPills++;
                if (usedPills > pills) return false;
            }
        }

        return true;
    }
};