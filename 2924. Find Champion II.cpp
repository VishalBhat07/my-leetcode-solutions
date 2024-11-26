class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int> indegree(n, 0);

        for (auto edge : edges)
            indegree[edge[1]]++;

        int champion = -1;
        int champCount = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                champCount++;
                champion = i;

                if (champCount > 1)
                    return -1;
            }
        }

        return champion;
    }
};
