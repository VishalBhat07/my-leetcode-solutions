class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        int rows[] = {0, -1, 0, 1};
        int cols[] = {-1, 0, 1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0 && !vis[i][j]) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            q.pop();
            dis[row][col] = dist;

            for (int k = 0; k < 4; k++) {
                int nrow = row + rows[k];
                int ncol = col + cols[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol]) {
                    q.push({{nrow, ncol}, dist + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return dis;
    }
};
