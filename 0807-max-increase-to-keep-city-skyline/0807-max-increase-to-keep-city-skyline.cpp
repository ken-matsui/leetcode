class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxValsInRow;
        vector<int> maxValsInCol;

        const size_t size = grid.size();
        for (int i = 0; i < size; ++i) {
            maxValsInRow.emplace_back(
                *max_element(grid[i].begin(), grid[i].end()));

            int maxVal = -1;
            for (int j = 0; j < size; ++j) {
                if (maxVal < grid[j][i]) {
                    maxVal = grid[j][i];
                }
            }
            maxValsInCol.emplace_back(maxVal);
        }

        int sum = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                const int minVal = min(maxValsInRow[i], maxValsInCol[j]);
                sum += max(minVal - grid[i][j], 0);
            }
        }
        return sum;
    }
};
