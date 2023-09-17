class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<unordered_set<int>> graph(n);

        // adjacency list
        for (const auto& p : paths) {
            graph[p[0] - 1].insert(p[1] - 1);
            graph[p[1] - 1].insert(p[0] - 1);
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            bool colors[5] = {}; // 4 colors

            for (const int neighbor : graph[i]) {
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
