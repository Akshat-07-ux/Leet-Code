class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build adjacency list and compute in-degree
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        vector<vector<int>> count(n, vector<int>(26, 0)); // color count per node
        queue<int> q;

        // Initialize queue with zero in-degree nodes
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int visited = 0;
        int answer = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            // Update count for this node's color
            count[node][colors[node] - 'a']++;

            // Update neighbors
            for (int neighbor : adj[node]) {
                for (int c = 0; c < 26; ++c) {
                    count[neighbor][c] = max(count[neighbor][c], count[node][c]);
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }

            // Track the max color count
            answer = max(answer, *max_element(count[node].begin(), count[node].end()));
        }

        // If we didn't visit all nodes, there was a cycle
        return visited == n ? answer : -1;
    }
};