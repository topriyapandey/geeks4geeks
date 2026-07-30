class Solution {
  public:
    void dfsHelper(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans) {
        visited[node] = true;
        ans.push_back(node);

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfsHelper(nbr, adj, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> ans;

        dfsHelper(0, adj, visited, ans);

        return ans;
    }
};