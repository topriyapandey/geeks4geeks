class Solution {
public:
    vector<int> bit;

    void update(int x, int val) {
        while (x <= 1000) {
            bit[x] = max(bit[x], val);
            x += x & -x;
        }
    }

    int query(int x) {
        int ans = 0;

        while (x > 0) {
            ans = max(ans, bit[x]);
            x -= x & -x;
        }

        return ans;
    }

    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();

        vector<pair<int, int>> discs;

        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
        }

        sort(discs.begin(), discs.end());

        bit.assign(1002, 0);

        int answer = 0;

        int i = 0;

        while (i < n) {
            int j = i;

            while (j < n && discs[j].first == discs[i].first) {
                j++;
            }

            vector<pair<int, int>> temp;

            for (int k = i; k < j; k++) {
                int height = discs[k].second;

                int best = query(height - 1);

                temp.push_back({height, best + height});

                answer = max(answer, best + height);
            }

            for (auto p : temp) {
                update(p.first, p.second);
            }

            i = j;
        }

        return answer;
    }
};