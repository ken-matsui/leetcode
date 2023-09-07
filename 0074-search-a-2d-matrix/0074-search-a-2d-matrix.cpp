class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        int lo = 0;
        int hi = m-1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;

            if (target == matrix[mi][0]) {
                return true;
            } else if (target > matrix[mi][0]) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }

        const int i = hi;
        if (i < 0) return false;

        lo = 0;
        hi = n-1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;

            if (target == matrix[i][mi]) {
                return true;
            } else if (target > matrix[i][mi]) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }

        return false;
    }
};