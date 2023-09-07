class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        // bottom-left
        int i = m-1;
        int j = 0;

        while (i >= 0 && j < n) {
            if (target == matrix[i][j]) {
                return true;
            } else if (target < matrix[i][j]) {
                --i;
            } else {
                ++j;
            }
        }

        return false;
    }
};