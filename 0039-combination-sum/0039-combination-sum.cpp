class Solution {
    vector<vector<int>> res;

    void backtrack(const vector<int>& candidates, const int target,
                   vector<int>& cur, const int start) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], cur, i);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        backtrack(candidates, target, cur, 0);
        return res;
    }
};
