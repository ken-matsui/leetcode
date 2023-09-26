class Solution {
    vector<vector<int>> res;
    
    void backtrack(const vector<int>& nums, vector<int>& cur, const int start) {
        res.push_back(cur);
        
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(nums, cur, i + 1);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(nums, cur, 0);
        return res;
    }
};