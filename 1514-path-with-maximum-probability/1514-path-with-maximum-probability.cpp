class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Create an adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start_node);

       
        vector<double> probabilities(n, 0.0);
        probabilities[start_node] = 1.0;

        while (!pq.empty()) {
            auto [currProb, node] = pq.top();
            pq.pop();

            
            if (node == end_node) return currProb;

            
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = currProb * edgeProb;
                if (newProb > probabilities[neighbor]) {
                    probabilities[neighbor] = newProb;
                    pq.emplace(newProb, neighbor);
                }
            }
        }

        // If no path was found
        return 0.0;
    }
};