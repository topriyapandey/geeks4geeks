class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfs(nbr, adj, visited);
            }
        }
    }

    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;
    }
};