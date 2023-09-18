class Solution {
    bool hasCycle(int parent, int node, const vector<vector<int>>& adjList, vector<bool>& visited) {
        if (visited[node]) {
            return true;
        }
        visited[node] = true;
        
        for (int neighbor : adjList[node]) {
            if (neighbor == parent) {
                continue;
            }
            if (hasCycle(node, neighbor, adjList, visited)) {
                return true;
            }
        }
        return false;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        
        if (hasCycle(-1, 0, adjList, visited)) {
            return false;
        }
        
        // every node is connected?
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        
        return true;
    }
};
