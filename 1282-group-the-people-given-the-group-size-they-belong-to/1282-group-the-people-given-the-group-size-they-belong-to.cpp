class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> output;
        unordered_map<int, vector<int>> cache;

        const size_t size = groupSizes.size();
        for (int i = 0; i < size; ++i) {
            cache[groupSizes[i]].emplace_back(i);

            if (cache[groupSizes[i]].size() == groupSizes[i]) {
                output.emplace_back(cache[groupSizes[i]]);
                cache[groupSizes[i]] = {};
            }
        }

        return output;
    }
};
