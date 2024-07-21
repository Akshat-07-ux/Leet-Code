class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Topological sort function
        auto topologicalSort = [&](vector<vector<int>>& conditions, int size) -> vector<int> {
            vector<int> indegree(size, 0);
            unordered_map<int, vector<int>> graph;

            for (auto& condition : conditions) {
                graph[condition[0]].push_back(condition[1]);
                indegree[condition[1] - 1]++;
            }

            queue<int> q;
            for (int i = 1; i <= size; ++i) {
                if (indegree[i - 1] == 0) {
                    q.push(i);
                }
            }

            vector<int> order;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);

                for (int neighbor : graph[node]) {
                    indegree[neighbor - 1]--;
                    if (indegree[neighbor - 1] == 0) {
                        q.push(neighbor);
                    }
                }
            }

            return order.size() == size ? order : vector<int>();
        };

        vector<int> rowOrder = topologicalSort(rowConditions, k);
        vector<int> colOrder = topologicalSort(colConditions, k);

        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowPosition;
        unordered_map<int, int> colPosition;

        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }

        for (int i = 1; i <= k; ++i) {
            matrix[rowPosition[i]][colPosition[i]] = i;
        }

        return matrix;
    }
};