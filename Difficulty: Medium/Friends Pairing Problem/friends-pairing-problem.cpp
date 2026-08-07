class Solution {
public:
    int countFriendsPairings(int n) {
        const int MOD = 1e9 + 7;

        if (n <= 2)
            return n;

        vector<long long> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + (long long)(i - 1) * dp[i - 2]) % MOD;
        }

        return dp[n];
    }
};