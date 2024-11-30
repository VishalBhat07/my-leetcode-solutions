class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> inDegree, outDegree;

    int getStartNode() {
        int start_node;
        for (auto& [node, degree] : outDegree) {
            if (degree - inDegree[node] == 1)
                return node;
            if (degree > 0)
                start_node = node;
        }
        return start_node;
    }

    void getEulerianPath(int curr, vector<int>& eulerian_path) {
        while (outDegree[curr]) {
            outDegree[curr]--;
            int next_node = adj[curr][outDegree[curr]];
            getEulerianPath(next_node, eulerian_path);
        }
        eulerian_path.push_back(curr);
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        for (auto& pair : pairs) {
            int from = pair[0];
            int to = pair[1];

            adj[from].push_back(to);
            outDegree[from]++;
            inDegree[to]++;
        }

        int start_node = getStartNode();

        vector<int> eulerian_path;
        getEulerianPath(start_node, eulerian_path);

        vector<vector<int>> res;
        for (int i = eulerian_path.size() - 1; i > 0; --i) {
            vector<int> path;
            path.push_back(eulerian_path[i]);
            path.push_back(eulerian_path[i - 1]);
            res.push_back(path);
        }
        return res;
    }
};
