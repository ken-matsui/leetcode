class Solution {
    int m;
    int n;

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
             const int i, const int j, bool& isSubIsland) {
        grid2[i][j] = 0; // mark as visited

        if (grid1[i][j] != 1) {
            isSubIsland = false;
        }

        // bottom
        if (i + 1 < m && grid2[i + 1][j] == 1) {
            dfs(grid1, grid2, i + 1, j, isSubIsland);
        }
        // up
        if (i - 1 >= 0 && grid2[i - 1][j] == 1) {
            dfs(grid1, grid2, i - 1, j, isSubIsland);
        }
        // right
        if (j + 1 < n && grid2[i][j + 1] == 1) {
            dfs(grid1, grid2, i, j + 1, isSubIsland);
        }
        // left
        if (j - 1 >= 0 && grid2[i][j - 1] == 1) {
            dfs(grid1, grid2, i, j - 1, isSubIsland);
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    bool isSubIsland = true;
                    dfs(grid1, grid2, i, j, isSubIsland);
                    if (isSubIsland) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
