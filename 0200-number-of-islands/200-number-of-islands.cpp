class Solution {
    size_t rs;
    size_t cs;
    
public:
    void findIsland(vector<vector<char>>& grid, const int r, const int c) {
        grid[r][c] = '0'; // disable this island;

        if (const int left = r - 1; left >= 0 && grid[left][c] == '1') {
            findIsland(grid, left, c);
        }
        if (const int right = r + 1; right < rs && grid[right][c] == '1') {
            findIsland(grid, right, c);
        }
        if (const int top = c - 1; top >= 0 && grid[r][top] == '1') {
            findIsland(grid, r, top);
        }
        if (const int bottom = c + 1; bottom < cs && grid[r][bottom] == '1') {
            findIsland(grid, r, bottom);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        rs = grid.size();
        cs = grid[0].size();

        int num = 0;
        for (int r = 0; r < rs; ++r) {
            for (int c = 0; c < cs; ++c) {
                if (grid[r][c] == '1') {
                    ++num;
                    findIsland(grid, r, c);
                }
            }
        }
        return num;
    }
};
