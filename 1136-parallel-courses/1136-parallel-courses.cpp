class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adjList(n + 1);
        vector<int> inDegree(n + 1, 0);
        for (const auto& edge : relations) {
            adjList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        vector<int> zeroInDegree;
        for (int i = 1; i < n + 1; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push_back(i);
            }
        }

        int sem = 0;
        int count = 0;
        while (!zeroInDegree.empty()) {
            ++sem;
            vector<int> next;
            for (int node : zeroInDegree) {
                ++count;
                for (const int neighbor : adjList[node]) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0) {
                        next.push_back(neighbor);
                    }
                }
            }
            zeroInDegree = next;
        }
        return count == n ? sem : -1;
    }
};