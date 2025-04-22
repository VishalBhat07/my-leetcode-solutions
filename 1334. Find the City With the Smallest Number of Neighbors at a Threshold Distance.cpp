class Solution {
private:
    vector<vector<int>> createAdjMatrix(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V, vector<int>(V, 1e9));
        for (int i = 0; i < V; i++)
            adj[i][i] = 0;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        return adj;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> adj =
            createAdjMatrix(n, edges);

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][k] == 1e9 || adj[k][j] == 1e9)
                        continue;
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        
        pair<int,int> ans = {-1, n};
        for (int i = 0; i < n; i++) {
            int cityCount = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distanceThreshold)
                    cityCount++;
            }  
            if(cityCount <= ans.second){
                ans.first = i;
                ans.second = cityCount;
            }
        }
        return ans.first;
    }
};
