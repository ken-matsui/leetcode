class Solution {
    bool dfs(unordered_map<int, vector<int>>& adjList,
             unordered_set<int>& visited, const int parent, const int node) {
        if (visited.find(parent) != visited.end()) {
            return false;
        }
        visited.insert(parent);
        if (parent == node) {
            return true;
        }

        for (const int neighbor : adjList[parent]) {
            if (dfs(adjList, visited, neighbor, node)) {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (const auto& edge : edges) {
            unordered_set<int> visited;
            if (!adjList[edge[0]].empty() && !adjList[edge[1]].empty() &&
                dfs(adjList, visited, edge[0], edge[1])) {
                return edge;
            }
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return {-1, -1};
    }
};
