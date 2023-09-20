class Solution {
    class UnionFind {
        vector<int> parent, rank;

    public:
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int findSet(int i) {
            if (parent[i] != i) {
                parent[i] = findSet(parent[i]);
            }
            return parent[i];
        }

        bool unionSet(int i, int j) {
            int pi = findSet(i);
            int pj = findSet(j);
            if (pi == pj) {
                return false;
            }
            if (rank[pi] < rank[pj]) {
                parent[pi] = pj;
            } else {
                parent[pj] = pi;
                if (rank[pi] == rank[pj]) {
                    rank[pi]++;
                }
            }
            return true;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        UnionFind uf(n);
        int res = 0;
        for (auto& edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            if (uf.unionSet(u, v)) {
                res += edge.first;
            }
        }

        return res;
    }
};
