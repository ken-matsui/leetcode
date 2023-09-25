class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : paths) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            bool colors[5] = {}; // 4 colors

            for (const int neighbor : adjList[i]) {
                colors[res[neighbor]] = true;
            }

            // Find unused color
            for (int c = 1; c <= 4; ++c) {
                if (!colors[c]) {
                    res[i] = c;
                    break;
                }
            }
        }
        return res;
    }
};
