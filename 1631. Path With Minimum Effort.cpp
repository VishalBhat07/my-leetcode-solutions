class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, -1, 0, 1};

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [row, col] = pq.top().second;
            int effort = pq.top().first;

            pq.pop();

            if (row == n - 1 && col == m - 1)
                return effort;

            for (int i = 0; i < 4; i++) {
                int nrow = row + rows[i];
                int ncol = col + cols[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newEffort = max(
                        effort, abs(heights[nrow][ncol] - heights[row][col]));
                    if (newEffort < dis[nrow][ncol]) {
                        dis[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
