class Solution {
public:
    long long maxProduct(vector<int>& arr, int k) {
        const long long NEG = -(1LL << 60);
        const long long POS = (1LL << 60);

        vector<vector<long long>> mx(k + 1, vector<long long>(2, NEG));
        vector<vector<long long>> mn(k + 1, vector<long long>(2, POS));

        mx[0][0] = mn[0][0] = 1;

        for (int x : arr) {
            for (int j = k; j >= 1; j--) {
                if (mx[j - 1][0] != NEG) {
                    long long p = mx[j - 1][0] * x;
                    long long q = mn[j - 1][0] * x;

                    mx[j][0] = max(mx[j][0], max(p, q));
                    mn[j][0] = min(mn[j][0], min(p, q));
                }

                if (x == 0) {
                    mx[j][0] = max(mx[j][0], 0LL);
                    mn[j][0] = min(mn[j][0], 0LL);
                }
            }
        }

        return mx[k][0];
    }
};