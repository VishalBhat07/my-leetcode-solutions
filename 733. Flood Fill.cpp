class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int rows[] = {0, 1, 0, -1};
        int cols[] = {-1, 0, 1, 0};
        q.push({sr, sc});
        vis[sr][sc] = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + rows[i];
                int ncol = col + cols[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    (image[nrow][ncol] == image[sr][sc]) &&
                    (vis[nrow][ncol] == 0)) {
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        image[sr][sc] = color;

        return image;
    }
};
