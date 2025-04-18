class Solution {
    
    vector<int> rows = {-1, 0, 1, 0};
    vector<int> cols = {0, -1, 0, 1};
    int n, m;
        
    private :
        void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid,
        int prow, int pcol, vector<pair<int,int>> &temp){
            vis[row][col] = 1;
            temp.push_back({row - prow, col - pcol});
            
            for(int i = 0 ; i < 4; i++){
                int nrow = row + rows[i];
                int ncol = col + cols[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                    dfs(nrow, ncol, vis, grid, prow, pcol, temp);
            }
        }
    
    public:
        int countDistinctIslands(vector<vector<int>>& grid) {
            
            n = grid.size();
            m = grid[0].size();
            
            vector<vector<int>> vis(n, vector<int>(m, 0));
            set<vector<pair<int,int>>> st;
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        vector<pair<int,int>> temp;
                        dfs(i, j, vis, grid, i, j, temp);
                        st.insert(temp);
                    }
                }
            }
            return st.size();
        }
};

