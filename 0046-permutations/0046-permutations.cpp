class Solution {
    vector<vector<int>> res;
    
    void backtrack(const vector<int>& nums, vector<int>& cur) {
        if (nums.size() == cur.size()) {
            res.push_back(cur);
            return;
        }

        for (const int num : nums) {
            if (find(cur.begin(), cur.end(), num) != cur.end()) {
                continue;
            }
            cur.push_back(num);
            backtrack(nums, cur);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        backtrack(nums, cur);
        return res;
    }
};