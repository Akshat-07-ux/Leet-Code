class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, vector<int>& component) {
        visited.insert(node);
        component.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }
    
    bool isCompleteComponent(vector<int>& component, unordered_map<int, unordered_set<int>>& adj) {
        int size = component.size();
        for (int node : component) {
            if (adj[node].size() != size - 1) {
                return false; // Not a complete component
            }
        }
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, unordered_set<int>> adjSet;
        unordered_set<int> visited;
        
        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            adjSet[edge[0]].insert(edge[1]);
            adjSet[edge[1]].insert(edge[0]);
        }
        
        int completeCount = 0;
        
        // Traverse all nodes
        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                vector<int> component;
                dfs(i, adj, visited, component);
                if (isCompleteComponent(component, adjSet)) {
                    completeCount++;
                }
            }
        }
        
        return completeCount;
    }
};