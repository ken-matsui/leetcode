class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const size_t colSize = mat.size();
        const size_t rowSize = mat[0].size();

        unordered_map<int, deque<int>> diag;

        for (int i = 0; i < colSize; ++i) {
            for (int j = 0; j < rowSize; ++j) {
                diag[i - j].emplace_back(mat[i][j]);
            }
        }

        for (auto& [key, val] : diag) {
            sort(val.begin(), val.end());
        }

        for (int i = 0; i < colSize; ++i) {
            for (int j = 0; j < rowSize; ++j) {
                mat[i][j] = diag[i - j][0];
                diag[i - j].pop_front();
            }
        }

        return mat;
    }
};
