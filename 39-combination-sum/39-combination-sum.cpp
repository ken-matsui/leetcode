class Solution {
    size_t size;
    vector<vector<int>> out;
    vector<int> tmp;

public:
    void backtrack(const vector<int>& candidates, const int start, const int target) {
        if (target == 0) {
            out.emplace_back(tmp);
        } else if (target > 0) {
            for (int i = start; i < size; ++i) {
                tmp.emplace_back(candidates[i]);
                backtrack(candidates, i, target - candidates[i]);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        size = candidates.size();
        sort(candidates.begin(), candidates.end(), greater<>());

        backtrack(candidates, 0, target);
        return out;
    }
};
