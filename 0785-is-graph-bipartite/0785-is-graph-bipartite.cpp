class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        if (color[node] == -1) {
            color[node] = 0;
        }

        for (const int neighbor : graph[node]) {
            if (color[neighbor] == color[node]) {
                return false;
            }
            if (color[neighbor] == -1) {
                color[neighbor] = color[node] ^ 1;
                if (!dfs(neighbor, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) {
                continue;
            }
            if (!dfs(i, graph, color)) {
                return false;
            }
        }
        return true;
    }
};
