class Solution {
    vector<vector<int>> res;
    
    void backtrack(const vector<int>& nums, vector<int>& cur, const int start) {
        res.push_back(cur);
        
        if (start >= nums.size()) {
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                // skip duplicates
                continue;
            }
            
            cur.push_back(nums[i]);
            backtrack(nums, cur, i + 1);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        backtrack(nums, cur, 0);
        return res;
    }
};