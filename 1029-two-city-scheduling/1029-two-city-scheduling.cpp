class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        const int size = costs.size();

        // cost diff -> original idx
        vector<pair<int, int>> costDiff(size);
        for (int i = 0; i < size; ++i) {
            costDiff[i] = {costs[i][0] - costs[i][1], i};
        }

        // minimize costs
        sort(costDiff.begin(), costDiff.end(),
             [](const auto& a, const auto& b) { return a.first < b.first; });

        int sum = 0;
        for (int i = 0; i < size / 2; ++i) {
            sum += costs[costDiff[i].second][0]; // choose A
        }
        for (int i = size / 2; i < size; ++i) {
            sum += costs[costDiff[i].second][1]; // choose B
        }
        return sum;
    }
};
