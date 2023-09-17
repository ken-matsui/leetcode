class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int row = grid.size();
        const int col = grid[0].size();
        
        int nodes = 0;
        int edges = 0;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    ++nodes;
                    
                    // right connection
                    if (j + 1 < col && grid[i][j + 1] == 1) {
                        ++edges;
                    }
                    // bottom connection
                    if (i + 1 < row && grid[i + 1][j] == 1) {
                        ++edges;
                    }
                }
            }
        }
        
        return 4 * nodes - 2 * edges;
    }
};