#include <vector>
#include <algorithm>

class Solution {
public:
    int largestSubsquare(std::vector<std::vector<char>>& mat) {
        int n = mat.size();
        std::vector<std::vector<int>> row(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> col(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'X') {
                    row[i][j] = (j == 0) ? 1 : row[i][j - 1] + 1;
                    col[i][j] = (i == 0) ? 1 : col[i - 1][j] + 1;
                }
            }
        }

        int max_side = 0;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int small = std::min(row[i][j], col[i][j]);

                while (small > max_side) {
                    if (row[i - small + 1][j] >= small && col[i][j - small + 1] >= small) {
                        max_side = small;
                        break;
                    }
                    small--;
                }
            }
        }

        return max_side;
    }
};