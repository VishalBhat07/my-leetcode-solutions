class Solution {

    const vector<int> rows = {0, -1, 0, 1};
    const vector<int> cols = {-1, 0, 1, 0};
    int n, m;

private:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis) {

        vis[row][col] = 1;

        for (int k = 0; k < 4; k++) {
            int nrow = row + rows[k];
            int ncol = col + cols[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        n = board.size();
        m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis);
            if (board[i][m - 1] == 'O' && !vis[i][m - 1])
                dfs(i, m - 1, board, vis);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis);
            if (board[n - 1][j] == 'O' && !vis[n - 1][j])
                dfs(n - 1, j, board, vis);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
    }
};
