class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Step 1: Build the adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // Step 2: Dijkstra's algorithm to find the shortest paths
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // Start from node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // (time, node)

        while (!pq.empty()) {
            auto [curTime, u] = pq.top();
            pq.pop();

            if (curTime > dist[u]) continue; // Ignore outdated entries

            for (auto& [v, time] : adj[u]) {
                long long newDist = curTime + time;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};