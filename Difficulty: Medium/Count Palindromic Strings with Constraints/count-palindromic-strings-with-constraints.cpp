class Solution {
public:
    long long palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;
        long long ans = 0;
        long long perm = 1;

        for (int len = 1; len <= n; len++) {
            int half = (len + 1) / 2;

            if (half > k) break;

            perm = 1;
            for (int i = 0; i < half; i++) {
                perm = (perm * (k - i)) % MOD;
            }

            if (len % 2 == 0) {
                ans = (ans + perm) % MOD;
            } else {
                ans = (ans + perm) % MOD;
            }
        }

        return ans;
    }
};