class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int shortestCycle = INT_MAX;
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            vector<int> visited(n, INT_MAX);
            vector<int> parent(n, -1);
            
            visited[i] = 0;
            q.push(i);

            while (!q.empty()) {
                const int src = q.front(); 
                q.pop();

                for (const int neighbor : adjList[src]) {
                    if (visited[neighbor] == INT_MAX) {
                        visited[neighbor] = visited[src] + 1;
                        parent[neighbor] = src;
                        q.push(neighbor);
                    } else {
                        if (parent[src] == neighbor || parent[neighbor] == src) {
                            continue;
                        }
                        
                        shortestCycle = min(shortestCycle, abs(visited[src] + visited[neighbor]) + 1);
                    }
                }
            }
        }

        return shortestCycle == INT_MAX ? -1 : shortestCycle;
    }
};
