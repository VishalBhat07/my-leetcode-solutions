
class Solution {
private:
    vector<vector<pair<int, int>>> createAdjList(int V,
                                                 vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);

        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        return adj;
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int mod = 1e9 + 7;
        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        vector<vector<pair<int, int>>> adj = createAdjList(n, roads);

        pq.push({0, 0});
        ways[0] = 1;
        dist[0] = 0;

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(dis > dist[node]) continue;

            for (auto& it : adj[node]) {
                if (dis + it.second < dist[it.first]) {
                    ways[it.first] = ways[node];
                    dist[it.first] = dis + it.second;
                    pq.push({dist[it.first], it.first});
                }else if(dis + it.second == dist[it.first]){
                    ways[it.first] = (ways[it.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};
