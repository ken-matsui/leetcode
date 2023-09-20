class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        if (freshCount == 0) {
            return 0;
        }

        int minutes = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) { // bfs
            const int size = q.size();
            bool rotten = false;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                // down
                if (x + 1 < m && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2; // make the orange rotten
                    --freshCount;
                    rotten = true;
                    q.push({x + 1, y});
                }
                // up
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2; // make the orange rotten
                    --freshCount;
                    rotten = true;
                    q.push({x - 1, y});
                }
                // right
                if (y + 1 < n && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2; // make the orange rotten
                    --freshCount;
                    rotten = true;
                    q.push({x, y + 1});
                }
                // left
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2; // make the orange rotten
                    --freshCount;
                    rotten = true;
                    q.push({x, y - 1});
                }
            }

            if (rotten) {
                ++minutes;
            }
        }

        return freshCount == 0 ? minutes : -1;
    }
};
