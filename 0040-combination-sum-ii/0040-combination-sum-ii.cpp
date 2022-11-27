class Solution {
    size_t size;
    vector<vector<int>> out;
    vector<int> tmp;

    void backtrack(vector<int>& candidates, const int start, const int target) {
        if (target == 0) {
            out.emplace_back(tmp);
        } else if (target > 0) {
            for (int i = start; i < size; ++i) {
                if (i > start && candidates[i - 1] == candidates[i]) {
                    // skip duplicates
                    continue;
                }
                tmp.emplace_back(candidates[i]);
                backtrack(candidates, i + 1, target - candidates[i]);
                tmp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        size = candidates.size();
        sort(candidates.begin(), candidates.end(), greater<>());

        backtrack(candidates, 0, target);
        return out;
    }
};
