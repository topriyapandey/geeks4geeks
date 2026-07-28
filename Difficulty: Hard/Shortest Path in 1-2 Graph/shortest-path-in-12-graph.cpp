class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> dist(V, INT_MAX);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            if (d > dist[node])
                continue;

            for (auto &nbr : adj[node]) {
                int next = nbr.first;
                int wt = nbr.second;

                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return (dist[dest] == INT_MAX) ? -1 : dist[dest];
    }
};