class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] > 0) {
            return state[node] == 2;
        }

        state[node] = 1; // mark as visited
        for (int next : graph[node]) {
            if (!dfs(next, graph, state)) {
                return false;
            }
        }
        state[node] = 2; // mark as safe
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> state(n, 0); // 0: unvisited, 1: visited, 2: safe
        vector<int> res;
        
        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, state)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
