class Solution {
private:
    vector<vector<int>> createAdjList(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1];
            int v = edges[i][0];

            adj[u].push_back(v);
        }
        return adj;
    }

    bool dfsCycleChecker(int node, vector<int>& vis,
                         vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCycleChecker(it, vis, pathVis, adj) == true)
                    return true;
            } else if (pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int V = numCourses;
        vector<vector<int>> adj = createAdjList(V, prerequisites);

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCycleChecker(i, vis, pathVis, adj) == true)
                    return false;
            }
        }
        return true;
    }
};
