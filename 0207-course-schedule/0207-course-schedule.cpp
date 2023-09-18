class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int count = 0;
        while (!zeroInDegree.empty()) {
            int node = zeroInDegree.front();
            zeroInDegree.pop();
            ++count;

            for (int& neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push(neighbor);
                }
            }
        }

        return count == numCourses;
    }
};
