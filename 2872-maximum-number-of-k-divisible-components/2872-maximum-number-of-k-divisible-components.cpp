class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        int components = 0;

        // Depth-First Search to calculate subtree sums and determine valid splits.
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long subtreeSum = values[node]; // Use long long to avoid overflow
            
            for (int neighbor : tree[node]) {
                if (neighbor != parent) {
                    subtreeSum += dfs(neighbor, node);
                }
            }

            // Check if this subtree can form a separate component.
            if (subtreeSum % k == 0) {
                components++;
                return 0LL; // This subtree is now an independent component.
            }

            return subtreeSum; // Return the current subtree sum to the parent.
        };

        dfs(0, -1);

        return components;
    }
};
