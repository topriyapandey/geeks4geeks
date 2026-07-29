class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        int V = adj.size();

        vector<bool> visited(V, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        return ans;
    }
};