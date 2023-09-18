class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto& edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> zeroInDegree;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push(i);
            }
        }

        // Kahn's algorithm
        vector<int> order;
        while (!zeroInDegree.empty()) {
            int node = zeroInDegree.front();
            zeroInDegree.pop();
            order.push_back(node);

            for (int& neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push(neighbor);
                }
            }
        }

        if (order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
};
