class Solution {
public:
    int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time, int change) {
        // Create the graph as an adjacency list
        std::vector<std::vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // BFS queue
        std::queue<std::pair<int, int>> q; // pair of (vertex, time)
        q.push({1, 0});
        
        // Distance array to store the shortest and second shortest times to each node
        std::vector<int> dist1(n + 1, INT_MAX);
        std::vector<int> dist2(n + 1, INT_MAX);
        dist1[1] = 0;

        while (!q.empty()) {
            auto [node, currentTime] = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                // Calculate the next time considering traffic light changes
                int nextTime = currentTime + time;
                if ((currentTime / change) % 2 == 1) {
                    nextTime = ((currentTime / change) + 1) * change + time;
                }

                // Update distances for the shortest and second shortest paths
                if (nextTime < dist1[neighbor]) {
                    std::swap(dist1[neighbor], nextTime);
                    q.push({neighbor, dist1[neighbor]});
                }
                if (nextTime > dist1[neighbor] && nextTime < dist2[neighbor]) {
                    dist2[neighbor] = nextTime;
                    q.push({neighbor, nextTime});
                }
            }
        }

        return dist2[n];
    }
};