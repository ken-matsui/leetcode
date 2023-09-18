class Solution {
    unordered_map<string,
                  priority_queue<string, vector<string>, greater<string>>>
        graph;
    vector<string> result;

    void visit(const string& airport) {
        while (!graph[airport].empty()) {
            const string next = graph[airport].top();
            graph[airport].pop();
            visit(next);
        }
        result.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        visit("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
