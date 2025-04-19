class Solution {
private:
    vector<vector<int>> reverseEdges(int V, vector<vector<int>>& graph) {

        vector<vector<int>> newGraph(V);

        for (int i = 0; i < V; i++)
            for (auto it : graph[i])
                newGraph[it].push_back(i);

        return newGraph;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<vector<int>> newGraph = reverseEdges(V, graph);

        vector<int> indegree(V, 0);
        vector<int> safeNodes;
        queue<int> q;

        for (int i = 0; i < V; i++)
            for (auto it : newGraph[i])
                indegree[it]++;

        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            for (auto it : newGraph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
