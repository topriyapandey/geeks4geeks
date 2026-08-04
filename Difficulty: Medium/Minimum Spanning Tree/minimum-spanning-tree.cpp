class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v)
            return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        DisjointSet ds(V);

        int sum = 0;

        for (auto &it : edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (ds.findParent(u) != ds.findParent(v)) {
                sum += wt;
                ds.unionByRank(u, v);
            }
        }

        return sum;
    }
};