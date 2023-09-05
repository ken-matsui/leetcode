class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> spiral;

        int vert = 0;
        int horiz = -1;

        int direc = 1;
        while (m * n > 0) {
            // move horizontally
            for (int i = 0; i < n; ++i) {
                horiz += direc;
                spiral.push_back(matrix[vert][horiz]);
            }
            --n; // update the boundary

            // move vertically
            --m; // update the boundary
            for (int i = 0; i < m; ++i) {
                vert += direc;
                spiral.push_back(matrix[vert][horiz]);
            }

            direc *= -1; // flip
        }

        return spiral;
    }
};
