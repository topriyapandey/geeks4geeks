class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();
        const int INF = -1;

        vector<vector<int>> dp(101, vector<int>(102, INF));
        dp[0][101] = 0;

        for (int x : arr) {
            vector<vector<int>> next = dp;

            for (int inc = 0; inc <= 100; inc++) {
                for (int dec = 1; dec <= 101; dec++) {
                    if (dp[inc][dec] == INF) {
                        continue;
                    }

                    int current = dp[inc][dec];

                    if (x > inc) {
                        next[x][dec] = max(next[x][dec], current + 1);
                    }

                    if (x < dec) {
                        next[inc][x] = max(next[inc][x], current + 1);
                    }
                }
            }

            dp = next;
        }

        int best = 0;

        for (int inc = 0; inc <= 100; inc++) {
            for (int dec = 1; dec <= 101; dec++) {
                best = max(best, dp[inc][dec]);
            }
        }

        return n - best;
    }
};