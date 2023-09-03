class Solution {
    int n;
    
    void trans(vector<vector<int>>& matrix) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }

    void rev(vector<vector<int>>& matrix) {
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();

        trans(matrix);
        rev(matrix);
    }
};
