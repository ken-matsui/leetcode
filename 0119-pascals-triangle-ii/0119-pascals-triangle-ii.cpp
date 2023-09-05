class Solution {
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        
        for (int i = 0; i < numRows; ++i) {
            res[i] = vector<int>(i+1, 1);
        }
        for (int i = 2; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }

        return res;
    }
    
public:
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex+1)[rowIndex];
    }
};