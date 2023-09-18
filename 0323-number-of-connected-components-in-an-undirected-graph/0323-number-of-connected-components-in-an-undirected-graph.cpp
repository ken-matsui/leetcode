class Solution {
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node) {
        visited[node] = true;
        
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(adjList, visited, neighbor);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++count;
                dfs(adjList, visited, i);
            }
        }
        return count;
    }
};