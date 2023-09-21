class Solution {
    void backtrack(const vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (const int num : nums) {
            if (find(path.begin(), path.end(), num) != path.end()) {
                continue;
            }
            path.push_back(num);
            backtrack(nums, path, res);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, path, res);
        return res;
    }
};