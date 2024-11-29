class Solution {
#define pip pair<int, pair<int, int>>
public:
    int minimumTime(vector<vector<int>>& grid) {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][1] > 1 + grid[0][0] and grid[1][0] > 1 + grid[0][0])
            return -1;

        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<pip, vector<pip>, greater<pip>> minheap;
        minheap.push({0, {0, 0}});
        visited[0][0] = true;

        while (!minheap.empty()) {
            pip curr = minheap.top();
            minheap.pop();

            int time = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if (x == m - 1 and y == n - 1)
                return time;

            for (int i = 0; i < 4; ++i) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                    !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    int new_time = 1 + time;
                    if (grid[newX][newY] > new_time)
                        new_time = (grid[newX][newY] - time) & 1
                                       ? grid[newX][newY]
                                       : grid[newX][newY] + 1;
                    minheap.push({new_time, {newX, newY}});
                }
            }
        }
        return -1;
    }
};
