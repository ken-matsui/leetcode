class Solution {
    void markConnected(vector<vector<char>>& grid, const int i, const int j) {
        // bottom
        if (i + 1 < m && grid[i + 1][j] == '1') {
            grid[i + 1][j] = '0';
            markConnected(grid, i + 1, j);
        }
        // right
        if (j + 1 < n && grid[i][j + 1] == '1') {
            grid[i][j + 1] = '0';
            markConnected(grid, i, j + 1);
        }
        // up
        if (i - 1 >= 0 && grid[i - 1][j] == '1') {
            grid[i - 1][j] = '0';
            markConnected(grid, i - 1, j);
        }
        // left
        if (j - 1 >= 0 && grid[i][j - 1] == '1') {
            grid[i][j - 1] = '0';
            markConnected(grid, i, j - 1);
        }
    }

    int m;
    int n;

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }

                ++count;
                markConnected(grid, i, j);
            }
        }
        return count;
    }
};
