class Solution {
public:
    int shortestPath(vector<vector<int>>& adj, int n) {
        queue<int> q;
        q.push(0);

        vector<bool> visited(n);
        visited[0] = true;
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1)
                    return distance;

                for (int adjacent : adj[curr]) {
                    if (!visited[adjacent]) {
                        visited[adjacent] = true;
                        q.push(adjacent);
                    }
                }
            }
            distance++;
        }
        return distance;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i)
            adj[i].push_back(i + 1);

        vector<int> res;
        for (auto& query : queries) {
            adj[query[0]].push_back(query[1]);
            res.push_back(shortestPath(adj, n));
        }
        return res;
    }
};
