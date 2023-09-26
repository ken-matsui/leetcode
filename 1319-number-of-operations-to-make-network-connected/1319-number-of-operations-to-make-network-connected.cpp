class Solution {
    void dfs(const vector<vector<int>>& adjList, const int node, vector<bool>& visited) {
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        for (const int neighbor : adjList[node]) {
            dfs(adjList, neighbor, visited);
        }
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adjList(n);
        for (const auto& edge : connections) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(adjList, i, visited);
                ++components;
            }
        }
        
        return components - 1;
    }
};