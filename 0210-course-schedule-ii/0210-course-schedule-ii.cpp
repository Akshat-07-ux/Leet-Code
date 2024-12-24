class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Adjacency list representation of the graph
        vector<vector<int>> adj(numCourses);
        // Array to store in-degrees of nodes
        vector<int> inDegree(numCourses, 0);
        
        // Build the graph and compute in-degrees
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }
        
        // Queue to process nodes with zero in-degree
        queue<int> zeroInDegree;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push(i);
            }
        }
        
        vector<int> order; // To store the topological order
        
        // Process nodes with zero in-degree
        while (!zeroInDegree.empty()) {
            int current = zeroInDegree.front();
            zeroInDegree.pop();
            order.push_back(current);
            
            // Reduce the in-degree of neighboring nodes
            for (int neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push(neighbor);
                }
            }
        }
        
        // If the order contains all courses, return it; otherwise, return an empty array
        return order.size() == numCourses ? order : vector<int>();
    }
};