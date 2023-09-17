class Solution {
    int m;
    int n;

    void dfs(const vector<vector<int>>& heights, const int i, const int j,
             vector<vector<bool>>& ocean) {
        ocean[i][j] = true;

        // bottom
        if (i + 1 < m && !ocean[i + 1][j] &&
            heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, i + 1, j, ocean);
        }
        // up
        if (i - 1 >= 0 && !ocean[i - 1][j] &&
            heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, i - 1, j, ocean);
        }
        // right
        if (j + 1 < n && !ocean[i][j + 1] &&
            heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, i, j + 1, ocean);
        }
        // left
        if (j - 1 >= 0 && !ocean[i][j - 1] &&
            heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, i, j - 1, ocean);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n - 1, atlantic);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, 0, j, pacific);
            dfs(heights, m - 1, j, atlantic);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
