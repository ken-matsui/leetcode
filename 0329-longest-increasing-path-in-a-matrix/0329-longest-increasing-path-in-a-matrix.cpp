class Solution {
    int m, n;
    vector<vector<int>> dp;

    int dfs(const vector<vector<int>>& matrix, const int i, const int j) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int maxLen = 1;

        const int right = j + 1;
        // check boundary & increasing?
        if (right < n && matrix[i][right] > matrix[i][j]) {
            maxLen = max(maxLen, 1 + dfs(matrix, i, right));
        }

        const int left = j - 1;
        // check boundary & increasing?
        if (left >= 0 && matrix[i][left] > matrix[i][j]) {
            maxLen = max(maxLen, 1 + dfs(matrix, i, left));
        }

        const int up = i + 1;
        // check boundary & increasing?
        if (up < m && matrix[up][j] > matrix[i][j]) {
            maxLen = max(maxLen, 1 + dfs(matrix, up, j));
        }

        const int down = i - 1;
        // check boundary & increasing?
        if (down >= 0 && matrix[down][j] > matrix[i][j]) {
            maxLen = max(maxLen, 1 + dfs(matrix, down, j));
        }

        dp[i][j] = maxLen; // memo
        return maxLen;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));

        int maxLen = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxLen = max(maxLen, dfs(matrix, i, j));
            }
        }
        return maxLen;
    }
};
