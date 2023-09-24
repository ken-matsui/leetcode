class Solution {
    vector<vector<int>> res;

    void backtrack(const vector<int>& candidates, const int target,
                   const int start, vector<int>& cur) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, cur);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        backtrack(candidates, target, 0, cur);
        return res;
    }
};
