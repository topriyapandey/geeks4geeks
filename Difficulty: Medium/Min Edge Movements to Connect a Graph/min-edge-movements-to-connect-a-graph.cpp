class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }

    int minEdgesReq(int n, vector<vector<int>>& adj) {
        if (adj.size() < n - 1)
            return -1;

        vector<int> parent(n), sz(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& edge : adj) {
            int u = edge[0];
            int v = edge[1];

            int pu = find(u, parent);
            int pv = find(v, parent);

            if (pu != pv) {
                if (sz[pu] < sz[pv])
                    swap(pu, pv);

                parent[pv] = pu;
                sz[pu] += sz[pv];
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i)
                components++;
        }

        return components - 1;
    }
};