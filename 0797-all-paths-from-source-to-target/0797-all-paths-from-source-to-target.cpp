class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;

    void dfs(const vector<vector<int>>& graph, const int i) {
        if (i == graph.size() - 1) {
            ans.push_back(tmp);
            return;
        }
        for (const auto& x : graph[i]) {
            tmp.push_back(x);
            dfs(graph, x);
            tmp.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        tmp.push_back(0);
        dfs(graph, 0);
        return ans;
    }
};
