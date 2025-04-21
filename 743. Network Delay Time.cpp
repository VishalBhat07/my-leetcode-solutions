class Solution {
private:
    vector<vector<pair<int, int>>> createAdjList(int V,
                                                 vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V + 1);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        return adj;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj = createAdjList(n, times);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n + 1, 1e9);
        dist[0] = -1;

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;

            pq.pop();

            for (auto it : adj[node]) {
                if (time + it.second < dist[it.first]) {
                    dist[it.first] = time + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        int ans = -1;
        for (auto it : dist) {
            if (it == 1e9)
                return -1;
            ans = max(ans, it);
        }

        return ans;
    }
};
