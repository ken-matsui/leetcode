class Solution {
    int m;
    int n;
    
    void dfs(vector<vector<int>>& grid, const int i, const int j, int& count) {
        if (grid[i][j] == -1) {
            return;
        }
        grid[i][j] = -1; // mark as visited
        
        // bottom
        if (i + 1 < m && grid[i + 1][j] == 1) {
            ++count;
            dfs(grid, i + 1, j, count);
        }
        // up
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            ++count;
            dfs(grid, i - 1, j, count);
        }
        // right
        if (j + 1 < n && grid[i][j + 1] == 1) {
            ++count;
            dfs(grid, i, j + 1, count);
        }
        // left
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            ++count;
            dfs(grid, i, j - 1, count);
        }
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int count = 1;
                    dfs(grid, i, j, count);
                    maxArea = max(maxArea, count);
                }
            }
        }
        return maxArea;
    }
};