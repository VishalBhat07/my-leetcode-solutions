class Solution {
private:
    vector<vector<int>> createAdjList(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1];
            int v = edges[i][0];

            adj[u].push_back(v);
        }
        return adj;
    }

    bool cycleCheckerDFS(int node, vector<int>& vis, vector<int>& pathVis,
                         vector<vector<int>>& adj) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (cycleCheckerDFS(it, vis, pathVis, adj) == true)
                    return true;
            } else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool checkCycle(int V, vector<vector<int>>& adj) {

        vector<int> vis(V);
        vector<int> pathVis(V);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (cycleCheckerDFS(i, vis, pathVis, adj) == true)
                    return true;
            }
        }

        return false;
    }

    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj,
             vector<int>& ans) {

        vis[node] = 1;
        for (auto it : adj[node])
            if (!vis[it])
                dfs(it, vis, adj, ans);
        ans.push_back(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj = createAdjList(numCourses, prerequisites);

        if (!checkCycle(numCourses, adj)) {
            vector<int> vis(numCourses);
            vector<int> ans;

            for (int i = 0; i < numCourses; i++) {
                if (!vis[i]) {
                    dfs(i, vis, adj, ans);
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }

        return {};
    }
};
