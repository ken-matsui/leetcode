class Solution {
    void backtrack(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);

        for (int i = start; i < nums.size(); ++i) {
            currentSubset.push_back(nums[i]);
            backtrack(nums, i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }
};