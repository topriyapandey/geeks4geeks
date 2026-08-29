class Solution {
public:
    int countSubsequences(string s, int n) {
        const int MOD = 1000000007;
        vector<int> dp(n, 0);

        for (char c : s) {
            int digit = c - '0';
            vector<int> next = dp;

            for (int rem = 0; rem < n; rem++) {
                if (dp[rem]) {
                    int newRem = (rem * 10 + digit) % n;
                    next[newRem] = (next[newRem] + dp[rem]) % MOD;
                }
            }

            next[digit % n] = (next[digit % n] + 1) % MOD;
            dp = next;
        }

        return dp[0];
    }
};
