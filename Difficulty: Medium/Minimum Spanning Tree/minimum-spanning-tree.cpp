class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[2] < b[2];
             });

        DSU dsu(V);

        int mstWeight = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dsu.unite(u, v))
                mstWeight += wt;
        }

        return mstWeight;
    }
};