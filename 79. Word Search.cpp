class Solution {
    vector<int> rows = {-1, 0, 1, 0};
    vector<int> cols = {0, -1, 0, 1};
    int n, m;

private:
    bool dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& board, string word, int iter) {

        if (iter == word.size() - 1)
            return true;

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + rows[i];
            int ncol = col + cols[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == word[iter + 1])
                if (dfs(nrow, ncol, vis, board, word, iter + 1) == true)
                    return true;
        }

        vis[row][col] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        n = board.size();
        m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, vis, board, word, 0) == true)
                        return true;
                }
            }
        }
        return false;
    }
};
