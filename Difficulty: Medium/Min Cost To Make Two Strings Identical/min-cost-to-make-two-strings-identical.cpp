#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinCost(std::string s1, std::string s2, int costS1, int costS2) {
        int m = s1.length();
        int n = s2.length();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLength = dp[m][n];
        return (m - lcsLength) * costS1 + (n - lcsLength) * costS2;
    }
};