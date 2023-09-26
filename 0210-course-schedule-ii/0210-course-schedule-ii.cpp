class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (const auto& edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> zeroInDegree;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push(i);
            }
        }

        vector<int> courses;
        while (!zeroInDegree.empty()) {
            const int node = zeroInDegree.front();
            zeroInDegree.pop();
            courses.push_back(node);

            for (const int neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push(neighbor);
                }
            }
        }

        if (courses.size() == numCourses) {
            return courses;
        } else {
            return {};
        }
    }
};
