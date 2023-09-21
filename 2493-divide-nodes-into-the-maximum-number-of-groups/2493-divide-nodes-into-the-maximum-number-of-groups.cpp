class Solution {
    vector<vector<int>> adjList, distance;
    vector<int> visit;

    bool bipartiteCheck(int start, vector<int>& component) {
        queue<int> q;
        q.push(start);
        visit[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            component.push_back(node);
            for (int neighbor : adjList[node]) {
                if (visit[neighbor] != -1) {
                    if (visit[neighbor] == visit[node]) {
                        return false;
                    }
                } else {
                    visit[neighbor] = !visit[node];
                    q.push(neighbor);
                }
            }
        }
        return true;
    }

    void calculateDistance(int start) {
        queue<int> q;
        q.push(start);
        distance[start][start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adjList[node]) {
                if (distance[start][neighbor] > distance[start][node] + 1) {
                    distance[start][neighbor] = distance[start][node] + 1;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        adjList.resize(n + 1);
        distance.resize(n + 1, vector<int>(n + 1, 1e9));
        visit.resize(n + 1, -1);

        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for (int i = 1; i <= n; ++i) {
            calculateDistance(i);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (visit[i] != -1) {
                continue;
            }

            vector<int> component;
            if (!bipartiteCheck(i, component)) {
                return -1;
            }

            int maxDistance = 0;
            for (int j : component) {
                for (int k : component) {
                    if (distance[j][k] < 1e9) {
                        maxDistance = max(maxDistance, distance[j][k]);
                    }
                }
            }
            ans += maxDistance;
        }

        for (int i = 1; i <= n; ++i) {
            for (int neighbor : adjList[i]) {
                if (visit[neighbor] == visit[i]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};
