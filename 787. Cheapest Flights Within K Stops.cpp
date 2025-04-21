class Solution {
    vector<vector<pair<int,int>>> createAdjList(int V, vector<vector<int>> &edges){
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }
        return adj;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj = createAdjList(n, flights);
        queue<pair<pair<int,int>,int>> q;
        vector<int> dist(n, INT_MAX);

        q.push({{0, src}, 0});
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front().first.second;
            int stops = q.front().first.first;
            int dis = q.front().second;

            q.pop();

            for(auto it : adj[node]){
                if(stops > k)
                    continue;
                if(dis + it.second < dist[it.first] && stops <= k){
                    dist[it.first] = dis + it.second;
                    q.push({{stops + 1, it.first}, dist[it.first]});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
