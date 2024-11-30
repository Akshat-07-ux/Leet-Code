class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        // Build the graph and track degrees
        for (const auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        // Find the starting node
        int startNode = pairs[0][0];
        for (const auto& [node, out] : outDegree) {
            if (out > inDegree[node]) {
                startNode = node;
                break;
            }
        }

        // Hierholzer's algorithm to find Eulerian path
        deque<int> path;
        stack<int> stack;
        stack.push(startNode);

        while (!stack.empty()) {
            int u = stack.top();
            if (!graph[u].empty()) {
                int v = graph[u].back();
                graph[u].pop_back();
                stack.push(v);
            } else {
                path.push_front(u);
                stack.pop();
            }
        }

        // Convert the path to the required format
        vector<vector<int>> result;
        auto it = path.begin();
        int prev = *it++;
        while (it != path.end()) {
            result.push_back({prev, *it});
            prev = *it++;
        }

        return result;
    }
};