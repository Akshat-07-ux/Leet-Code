class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        
        // Initial adjacency list for the initial road configuration
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back({i + 1, 1}); // unidirectional road with weight 1
        }

        auto dijkstra = [&](int start, int end) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            
            dist[start] = 0;
            pq.push({0, start});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                
                if (d > dist[u]) continue;
                
                for (auto [v, weight] : adj[u]) {
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            return dist[end];
        };
        
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            adj[u].push_back({v, 1});
            answer.push_back(dijkstra(0, n - 1));
        }

        return answer;
    }
};