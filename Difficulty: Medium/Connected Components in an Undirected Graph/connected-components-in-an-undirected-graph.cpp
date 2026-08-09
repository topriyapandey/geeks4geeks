class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,
             vector<int>& comp) {
        vis[node] = true;
        comp.push_back(node);

        for (int nbr : adj[node]) {
            if (!vis[nbr])
                dfs(nbr, adj, vis, comp);
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(V, false);
        vector<vector<int>> ans;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);
                ans.push_back(comp);
            }
        }

        return ans;
    }
};