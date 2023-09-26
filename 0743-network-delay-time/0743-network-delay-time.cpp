class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto& time : times) {
            graph[time[0]].emplace_back(time[1], time[2]);
        }
        
        // dist, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);
        
        unordered_map<int, int> dist;
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (dist.find(node) != dist.end()) {
                continue;
            }
            dist[node] = d;
            if (dist.size() == n) {
                break;
            }
            for (const auto& [next, w] : graph[node]) {
                if (dist.find(next) == dist.end()) {
                    pq.emplace(d + w, next);
                }
            }
        }
        
        if (dist.size() != n) {
            return -1;
        }
        int ans = 0;
        for (const auto& [node, d] : dist) {
            ans = max(ans, d);
        }
        return ans;
    }
};