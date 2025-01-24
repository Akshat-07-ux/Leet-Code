class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n); // Reverse graph representation
        vector<int> outDegree(n, 0);         // To store out-degree of each node
        
        // Build the reverse graph and compute out-degrees
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            outDegree[i] = graph[i].size();
        }
        
        queue<int> q; // Queue for processing nodes with 0 out-degree
        vector<int> safeNodes;
        
        // Add all terminal nodes (out-degree = 0) to the queue
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process the graph in reverse topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            // Reduce the out-degree of neighbors in the reverse graph
            for (int neighbor : reverseGraph[node]) {
                outDegree[neighbor]--;
                if (outDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Sort the safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};