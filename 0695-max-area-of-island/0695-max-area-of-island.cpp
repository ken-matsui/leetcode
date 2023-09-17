class Solution {
    void dfs(vector<vector<int>>& grid, const int i, const int j, int& curArea) {
        grid[i][j] = 0; // mark as visited
        ++curArea;
        
        // bottom
        if (i + 1 < m && grid[i + 1][j] == 1) {
            dfs(grid, i + 1, j, curArea);
        }
        // up
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            dfs(grid, i - 1, j, curArea);
        }
        // right
        if (j + 1 < n && grid[i][j + 1] == 1) {
            dfs(grid, i, j + 1, curArea);
        }
        // left
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            dfs(grid, i, j - 1, curArea);
        }
    }

    int m;
    int n;
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int curArea = 0;
                    dfs(grid, i, j, curArea);
                    if (curArea > maxArea) {
                        maxArea = curArea;
                    }
                }
            }
        }
        return maxArea;
    }
};