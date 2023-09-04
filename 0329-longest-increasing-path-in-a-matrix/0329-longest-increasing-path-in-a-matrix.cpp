class Solution {
    int m, n;
    vector<vector<int>> dp;

    int dfs(const vector<vector<int>>& matrix, const int x, const int y) {
        if (dp[x][y] != 0) {
            return dp[x][y];
        }

        int maxLen = 1;
        constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < 4; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] > matrix[x][y]) {
                maxLen = max(maxLen, 1 + dfs(matrix, newX, newY));
            }
        }

        dp[x][y] = maxLen; // memoize
        return maxLen;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int maxLen = 0;
        dp = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxLen = max(maxLen, dfs(matrix, i, j));
            }
        }

        return maxLen;
    }
};
