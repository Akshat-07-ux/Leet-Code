class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Adjacency list to represent the graph
        vector<vector<int>> graph(numCourses);
        // Array to track in-degrees of nodes
        vector<int> inDegree(numCourses, 0);

        // Build the graph and calculate in-degrees
        for (const auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[prerequisiteCourse].push_back(course);
            inDegree[course]++;
        }

        // Queue for nodes with in-degree 0
        queue<int> zeroDegreeQueue;

        // Add all nodes with in-degree 0 to the queue
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                zeroDegreeQueue.push(i);
            }
        }

        // Counter for the number of courses processed
        int processedCourses = 0;

        // Process the graph using BFS
        while (!zeroDegreeQueue.empty()) {
            int course = zeroDegreeQueue.front();
            zeroDegreeQueue.pop();
            processedCourses++;

            // Reduce in-degree of neighbors
            for (int neighbor : graph[course]) {
                inDegree[neighbor]--;
                // If in-degree becomes 0, add it to the queue
                if (inDegree[neighbor] == 0) {
                    zeroDegreeQueue.push(neighbor);
                }
            }
        }

        // If all courses have been processed, return true
        return processedCourses == numCourses;
    }
};