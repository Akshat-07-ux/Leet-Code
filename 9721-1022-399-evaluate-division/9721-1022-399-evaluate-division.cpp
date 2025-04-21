class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    bool dfs(string current, string target, unordered_set<string>& visited, double& result, double product) {
        if (current == target) {
            result = product;
            return true;
        }

        visited.insert(current);

        for (auto& neighbor : graph[current]) {
            if (!visited.count(neighbor.first)) {
                if (dfs(neighbor.first, target, visited, result, product * neighbor.second)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        graph.clear();

        // Step 1: Build graph
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }

        // Step 2: Answer queries
        vector<double> results;
        for (auto& q : queries) {
            string src = q[0];
            string dst = q[1];

            if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) {
                results.push_back(-1.0);
            } else if (src == dst) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double res = -1.0;
                dfs(src, dst, visited, res, 1.0);
                results.push_back(res);
            }
        }

        return results;
    }
};