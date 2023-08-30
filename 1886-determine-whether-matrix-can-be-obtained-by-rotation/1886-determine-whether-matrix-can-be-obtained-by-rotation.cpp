class Solution {
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size / 2 + size % 2; ++i) {
            for (int j = 0; j < size / 2; ++j) {
                int tmp = matrix[size - 1 - j][i];
                matrix[size - 1 - j][i] = matrix[size - 1 - i][size - j - 1];
                matrix[size - 1 - i][size - j - 1] = matrix[j][size - 1 - i];
                matrix[j][size - 1 - i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) {
            return true;
        }

        // try rotation 3 times
        for (int i = 0; i < 3; ++i) {
            rotate(mat);
            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};