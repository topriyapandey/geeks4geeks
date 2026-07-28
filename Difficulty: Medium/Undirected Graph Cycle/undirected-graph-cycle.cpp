class Solution {
public:
    bool bfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q;
        visited[src] = true;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, node});
                }
                else if (nbr != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, adj, visited))
                    return true;
            }
        }

        return false;
    }
};