class Solution {
public:
    pair<int,int> bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int far = start;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > dist[far]) {
                far = u;
            }

            for (int v : adj[u]) {
                v--;

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return {far, dist[far]};
    }

    int partyHouse(vector<vector<int>>& adj) {
        auto p1 = bfs(0, adj);
        auto p2 = bfs(p1.first, adj);

        int diameter = p2.second;

        return (diameter + 1) / 2;
    }
};