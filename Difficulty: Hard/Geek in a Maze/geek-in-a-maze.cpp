#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, std::vector<std::vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#') return 0;

        std::vector<std::vector<std::pair<int, int>>> max_moves(n, std::vector<std::pair<int, int>>(m, {-1, -1}));
        std::queue<std::tuple<int, int, int, int>> q;

        q.push({r, c, u, d});
        max_moves[r][c] = {u, d};

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [curr_r, curr_c, rem_u, rem_d] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = curr_r + dr[i];
                int nc = curr_c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.') {
                    int next_u = rem_u - (i == 0 ? 1 : 0);
                    int next_d = rem_d - (i == 1 ? 1 : 0);

                    if (next_u >= 0 && next_d >= 0) {
                        if (next_u > max_moves[nr][nc].first || next_d > max_moves[nr][nc].second) {
                            if (next_u > max_moves[nr][nc].first) max_moves[nr][nc].first = next_u;
                            if (next_d > max_moves[nr][nc].second) max_moves[nr][nc].second = next_d;

                            q.push({nr, nc, next_u, next_d});
                        }
                    }
                }
            }
        }

        int visited_count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (max_moves[i][j].first != -1) {
                    visited_count++;
                }
            }
        }

        return visited_count;
    }
};