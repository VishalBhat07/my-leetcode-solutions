class Solution {
#define pip pair<int, pair<int, int>>
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<pip, vector<pip>, greater<pip>> minheap;
        minheap.push({0, {0, 0}});
        visited[0][0] = true;

        while (!minheap.empty()) {
            pip curr = minheap.top();
            minheap.pop();

            int x = curr.second.first;
            int y = curr.second.second;
            int cost = curr.first;

            if (x == m - 1 and y == n - 1)
                return cost;

            for (int i = 0; i < 4; ++i) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                    !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    if (grid[newX][newY] == 1)
                        minheap.push({cost + 1, {newX, newY}});
                    else
                        minheap.push({cost, {newX, newY}});
                }
            }
        }
        return 0;
    }
};
