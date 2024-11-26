class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n);

        // Build the graph and calculate in-degrees
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // Find nodes with in-degree 0 (potential champions)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // If there are multiple nodes with in-degree 0, return -1
        if (q.size() != 1) {
            return -1;
        }

        // Perform BFS (Kahn's Algorithm) to check if the graph is valid
        int champion = q.front();
        q.pop();

        vector<bool> visited(n, false);
        visited[champion] = true;

        queue<int> bfsQueue;
        bfsQueue.push(champion);

        while (!bfsQueue.empty()) {
            int current = bfsQueue.front();
            bfsQueue.pop();

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }

        // Ensure all nodes are reachable from the champion
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && inDegree[i] > 0) {
                return -1;
            }
        }

        return champion;
    }
};