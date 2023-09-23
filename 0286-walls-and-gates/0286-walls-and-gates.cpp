class Solution {
    const int inf = 2147483647;

    int m;
    int n;

    void dfs(vector<vector<int>>& rooms, const int i, const int j,
             const int dist) {
        if (i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] == 0 ||
            rooms[i][j] == -1 || rooms[i][j] <= dist) {
            return;
        }

        rooms[i][j] = dist;
        // bottom
        dfs(rooms, i + 1, j, dist + 1);
        // up
        dfs(rooms, i - 1, j, dist + 1);
        // right
        dfs(rooms, i, j + 1, dist + 1);
        // left
        dfs(rooms, i, j - 1, dist + 1);
    }

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    // bottom
                    dfs(rooms, i + 1, j, 1);
                    // up
                    dfs(rooms, i - 1, j, 1);
                    // right
                    dfs(rooms, i, j + 1, 1);
                    // left
                    dfs(rooms, i, j - 1, 1);
                }
            }
        }
    }
};
