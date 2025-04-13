class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, pair<int, int>>> q;

        int rows[] = {0, -1, 0, 1};
        int cols[] = {-1, 0, 1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {

                    q.push({{i, j}, {-1, -1}});
                    vis[i][j] = 1;

                    while (!q.empty()) {
                        int row = q.front().first.first;
                        int col = q.front().first.second;
                        int parRow = q.front().second.first;
                        int parCol = q.front().second.second;

                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nrow = row + rows[k];
                            int ncol = col + cols[k];

                            if (nrow >= 0 && nrow < n && ncol >= 0 &&
                                ncol < m &&
                                grid[nrow][ncol] == grid[row][col]) {
                                if (!vis[nrow][ncol]) {
                                    vis[nrow][ncol] = 1;
                                    q.push({{nrow, ncol}, {row, col}});
                                } else if ((parRow != nrow || parCol != ncol)) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
            return false;
    }
};
