class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<pair<int, int>> pos;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    pos.push_back({i, j});
                }
            }
        }

        for (const auto [i, j] : pos) {
            for (int i2 = 0; i2 < m; ++i2) {
                matrix[i2][j] = 0;
            }
            for (int j2 = 0; j2 < n; ++j2) {
                matrix[i][j2] = 0;
            }
        }
    }
};
