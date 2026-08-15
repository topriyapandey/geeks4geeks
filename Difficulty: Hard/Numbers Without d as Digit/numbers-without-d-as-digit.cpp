class Solution {
public:
    long long dp[11][2][2];

    long long solve(string &s, int pos, bool tight, bool started, int d) {
        if (pos == s.size())
            return started ? 1 : 0;

        if (dp[pos][tight][started] != -1)
            return dp[pos][tight][started];

        int limit = tight ? s[pos] - '0' : 9;
        long long ans = 0;

        for (int dig = 0; dig <= limit; dig++) {
            bool ntight = tight && (dig == limit);
            bool nstarted = started || (dig != 0);

            if (nstarted && dig == d)
                continue;

            ans += solve(s, pos + 1, ntight, nstarted, d);
        }

        return dp[pos][tight][started] = ans;
    }

    long long countWithout(long long n, int d) {
        if (n <= 0) return 0;

        string s = to_string(n);
        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 1, 0, d);
    }
};