class Solution {
    int m;
    int n;
    vector<vector<int>> dp;

    int dfs(const vector<vector<int>>& matrix, const int i, const int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int maxPath = 1;
        // bottom
        if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) {
            maxPath = max(maxPath, dfs(matrix, i + 1, j) + 1);
        }
        // up
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            maxPath = max(maxPath, dfs(matrix, i - 1, j) + 1);
        }
        // right
        if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) {
            maxPath = max(maxPath, dfs(matrix, i, j + 1) + 1);
        }
        // left
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            maxPath = max(maxPath, dfs(matrix, i, j - 1) + 1);
        }
        dp[i][j] = maxPath;
        return maxPath;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));

        int maxPath = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxPath = max(maxPath, dfs(matrix, i, j));
            }
        }
        return maxPath;
    }
};
