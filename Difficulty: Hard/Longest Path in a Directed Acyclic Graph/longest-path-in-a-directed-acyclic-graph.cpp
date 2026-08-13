class Solution {
public:
    void topoSort(int node, vector<vector<pair<int,int>>>& adj,
                  vector<int>& vis, stack<int>& st) {
        vis[node] = 1;

        for (auto &it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> maxDistance(int V, int src, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (dist[u] == INT_MIN) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                int w = it.second;

                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        return dist;
    }
};