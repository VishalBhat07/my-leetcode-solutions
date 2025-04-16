class Solution {

    vector<int> rows = {0, -1, 0, 1};
    vector<int> cols = {-1, 0, 1, 0};
    int n, m;

private:
    void DFS(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        vis[row][col] = 1;
        for (int k = 0; k < 4; k++) {

            int nrow = row + rows[k];
            int ncol = col + cols[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                DFS(nrow, ncol, grid, vis);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (grid[i][0] && !vis[i][0])
                DFS(i, 0, grid, vis);

            if (grid[i][m - 1] && !vis[i][m - 1])
                DFS(i, m - 1, grid, vis);
        }

        for (int i = 0; i < m; i++) {
            if (grid[0][i] && !vis[0][i])
                DFS(0, i, grid, vis);

            if (grid[n - 1][i] && !vis[n - 1][i])
                DFS(n - 1, i, grid, vis);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;

        return count;
    }
};
