class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if (grid[0][0])
            return -1;

        int n = grid.size();

        vector<int> rows = {-1, 0, 1, 0, 1, 1, -1, -1};
        vector<int> cols = {0, 1, 0, -1, -1, 1, -1, 1};

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto [row, col] = q.front().second;
            int dis = q.front().first;

            q.pop();

            for (int i = 0; i < 8; i++) {
                int nrow = row + rows[i];
                int ncol = col + cols[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    if (nrow == n - 1 && ncol == n - 1)
                        return dis + 1;
                    q.push({1 + dis, {nrow, ncol}});
                }
            }
        }

        if (dist[n - 1][n - 1] == INT_MAX)
            return -1;

        return dist[n - 1][n - 1];
    }
};
