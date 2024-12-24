class Solution {
public:
    // Helper function to find the farthest node and distance from a given node
    pair<int, int> bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        int farthestNode = start, maxDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }

        return {farthestNode, maxDist};
    }

    // Function to compute the diameter of a tree
    int treeDiameter(vector<vector<int>>& edges, int nodes) {
        vector<vector<int>> adj(nodes);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 1: Find the farthest node from any starting node (e.g., node 0)
        auto [farthestNode, _] = bfs(0, adj);

        // Step 2: Find the farthest node from the previously found farthest node
        auto [_, diameter] = bfs(farthestNode, adj);

        return diameter;
    }

    // Function to find the minimum diameter after merging two trees
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1; // Number of nodes in the first tree
        int m = edges2.size() + 1; // Number of nodes in the second tree

        // Calculate diameters of the two trees
        int diameter1 = treeDiameter(edges1, n);
        int diameter2 = treeDiameter(edges2, m);

        // Minimum possible diameter after connecting the two trees
        return max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
    }
};