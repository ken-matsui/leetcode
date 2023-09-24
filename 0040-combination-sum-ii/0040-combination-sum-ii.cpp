class Solution {
    vector<vector<int>> res;
    
    void backtrack(const vector<int>& candidates, const int target, const int start, vector<int>& cur) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                // skip duplicates
                continue;
            }

            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, cur);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        backtrack(candidates, target, 0, cur);
        return res;
    }
};